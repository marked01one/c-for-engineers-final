#include<stdio.h>
#include<stdlib.h>


int string_len(char *s){
    int len;
    for (len = 0; s[len] != '\0'; ++len);
    return len;
}

int main(int argc, char **argv)
{
  /* Check whether there are exact number of arguments given */
  if (argc < 3){
    printf("Error: Please enter an argument!");
    return(-1);
  }
  if (argc > 3){
    printf("Error: Too many arguments!");
    return(-1);
  }
  /* Open the indicated text file & check whether the file is opened */
  FILE * fp = fopen(argv[2], "r");
  if (fp == NULL){
    perror("Error opening file");
    return -1;
  }
  int count = 0, found = 1;
  char *word = argv[1];
  int len = string_len(word);
  char *scan = (char*)malloc((len+1) * sizeof(char));
  /* Iterate through the entire file */
  while (!feof(fp)){
    fseek(fp, (-1)*(len-1), SEEK_CUR);
    fgets(scan,(len+1),fp);
    for (int i = 0; i < len; ++i){
      if (scan[i] != word[i]){
        found = 0;
        break;
      }
      found = 1;
    }
    count += found;
  }
  printf("Number of times the word '%s' appear in beemovie.txt: %d\n", word, count);
  fclose(fp);
  free(scan);
  return 0;
}