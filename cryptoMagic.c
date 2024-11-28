#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encryptFile(const char *inputFileName);
void decryptFile(const char *inputFileName);
void getOutputFileName(const char *inputFileName, char *outputFileName, const char *newExtension);
void processLineEncryption(const char *line, FILE *outputFile);
void processLineDecryption(const char *line, FILE *outputFile);

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s [-E|-D] inputFile\n", argv[0]);
        return 1;
    }

    // Determine mode (-E for encrypt, -D for decrypt, default is encrypt)
    int encryptMode = 1; // Default mode is encryption
    const char *inputFileName;

    if (argc == 3) {
        if (strcmp(argv[1], "-E") == 0) {
            encryptMode = 1;
        } else if (strcmp(argv[1], "-D") == 0) {
            encryptMode = 0;
        } else {
            fprintf(stderr, "Invalid option: %s. Use -E for encryption or -D for decryption.\n", argv[1]);
            return 1;
        }
        inputFileName = argv[2];
    } else {
        inputFileName = argv[1];
    }

    // Encrypt or decrypt based on mode
    if (encryptMode) {
        encryptFile(inputFileName);
    } else {
        decryptFile(inputFileName);
    }

    return 0;
}

void encryptFile(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    char outputFileName[256];
    getOutputFileName(inputFileName, outputFileName, ".crp");
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    char line[121]; // Max 120 characters + 1 for null terminator
    while (fgets(line, sizeof(line), inputFile)) {
        processLineEncryption(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete. Encrypted file: %s\n", outputFileName);
}

void decryptFile(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    char outputFileName[256];
    getOutputFileName(inputFileName, outputFileName, ".txt");
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    char line[256]; // Max 255 characters for encrypted lines
    while (fgets(line, sizeof(line), inputFile)) {
        processLineDecryption(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Decryption complete. Decrypted file: %s\n", outputFileName);
}

void getOutputFileName(const char *inputFileName, char *outputFileName, const char *newExtension) {
    char *dot = strrchr(inputFileName, '.');
    if (dot) {
        size_t baseLength = dot - inputFileName;
        strncpy(outputFileName, inputFileName, baseLength);
        outputFileName[baseLength] = '\0';
    } else {
        strcpy(outputFileName, inputFileName);
    }
    strcat(outputFileName, newExtension);
}

void processLineEncryption(const char *line, FILE *outputFile) {
    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];
        if (c == '\t') {
            fputs("TT", outputFile);
        } else if (c == '\n') {
            fputc('\n', outputFile);
        } else {
            int outChar = c - 16;
            if (outChar < 32) {
                outChar = (outChar - 32) + 144;
            }
            fprintf(outputFile, "%02X", outChar);
        }
    }
}

void processLineDecryption(const char *line, FILE *outputFile) {
    for (int i = 0; line[i] != '\0';) {
        if (line[i] == 'T' && line[i + 1] == 'T') {
            fputc('\t', outputFile);
            i += 2;
        } else if (line[i] == '\n') {
            fputc('\n', outputFile);
            i++;
        } else {
            char hexPair[3] = {line[i], line[i + 1], '\0'};
            int outChar = (int)strtol(hexPair, NULL, 16);
            outChar += 16;
            if (outChar > 127) {
                outChar = (outChar - 144) + 32;
            }
            fputc(outChar, outputFile);
            i += 2;
        }
    }
}
