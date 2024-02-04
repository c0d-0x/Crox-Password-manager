#include "password.h"

FILE *database_ptr;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    help();
    return 1;
  }
  password_t *password = NULL;
  password = malloc(sizeof(password_t));
  if (password == NULL) {
    perror("Memory allocation fail");
    return 1;
  }
  if (strncmp(argv[1], "-h", sizeof(char) * 2) == 0) {

    help();
  } else if (strncmp(argv[1], "-s", sizeof(char) * 2) == 0) {

    if (argc != 5) {
      fprintf(stderr, " usage: %s <-s> <password> <username> <description>",
              argv[0]);
      return 1;
    }
    // Authenication[TODO]
    if ((strlen(argv[2]) > PASSLENGTH) ||
        (strlen(argv[3]) > ACCLENGTH || (strlen(argv[4]) > DESCLENGTH))) {
      fprintf(stderr,
              "MAX PASSLENGTH: %d & MAX ACCLENGTH: %d & MAX DESCLENGTH: %d\n",
              PASSLENGTH, ACCLENGTH, DESCLENGTH);
      return 1;
    }

    strcpy(password->passd, argv[2]);
    strcpy(password->username, argv[3]);
    strcpy(password->description, argv[4]);
    save_password(password, database_ptr);

  } else if (strncmp(argv[1], "-l", sizeof(char) * 2) == 0) {

    // Authenication[TODO]
    list_all_passwords(database_ptr);

  } else if (strncmp(argv[1], "-r", sizeof(char) * 2) == 0) {

    char *password = random_password();
    printf("%s\n", password);
    free(password);
  } else if (strncmp(argv[1], "-c", sizeof(char) * 2) == 0) {
    if (argc != 3) {
      fprintf(stderr, " usage: %s <-c> <username>", argv[1]);
    }

    // Authenication[TODO]
    // shearch[TODO]
  } else if (strncmp(argv[1], "-e", sizeof(char) * 2) == 0) {
    if (argc != 3) {
      fprintf(stderr, " usage: %s <-e> <csv file>", argv[1]);
    }
    export_pass(database_ptr, argv[2]);
  } else if (strncmp(argv[1], "-i", sizeof(char) * 2) == 0) {
    if (argc != 3) {
      fprintf(stderr, " usage: %s <-i> <csv file>", argv[1]);
    }
    import_pass(database_ptr, argv[2]);
  } else {
    help();
  }
  free(password);
  return EXIT_SUCCESS;
}
