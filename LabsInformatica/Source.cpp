#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <clocale>

void extract_letters(const char* str, char* vowels, char* consonants) {
    int vowel_count = 0;
    int consonant_count = 0;

    memset(vowels, 0, 27);
    memset(consonants, 0, 27);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);

        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                int found = 0;
                for (int j = 0; j < vowel_count; j++) {
                    if (vowels[j] == c) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    vowels[vowel_count++] = c;
                }
            }
            else {

                int found = 0;
                for (int j = 0; j < consonant_count; j++) {
                    if (consonants[j] == c) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    consonants[consonant_count++] = c;
                }
            }
        }
    }
    vowels[vowel_count] = '\0';
    consonants[consonant_count] = '\0';
}

void sort_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
void process_string(const char* input, char* output) {
    char vowels[27] = { 0 };
    char consonants[27] = { 0 };

    extract_letters(input, vowels, consonants);

    sort_string(vowels);
    sort_string(consonants);

    int vowel_len = strlen(vowels);
    int consonant_len = strlen(consonants);

    if (vowel_len > consonant_len) {
        strcpy(output, vowels);
    }
    else {
        strcpy(output, consonants);
    }
}
int main()
{
    setlocale(LC_ALL, "RU-ru");
	const char *input_filename = "data.txt";
	char output_filename[50], line[256], result[27];

	printf("¬ведите название выходного файла: ");
	scanf("%s", output_filename);
	FILE* ifile = fopen(input_filename, "r");
	FILE* ofile = fopen(output_filename, "w");
	if (ifile || ofile)
	{
		while (fgets(line, sizeof(line), ifile))
		{
			line[strcspn(line, "\n")] = '\0';
            process_string(line, result);

			fprintf(ofile,"%s\n",result);
		}
		
		fclose(ifile);
		fclose(ofile);
		printf("Success!");
	}

}