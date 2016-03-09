/*
 * Header file od logging funkcij.
 */

void write(char *message);

void init_write(char *message);

void warning_write(char *message);

void init_warning_write(char *message);

int error_write(int errno);

int init_error_write(int errno);
