/*
 * Header file od logging funkcij.
 */

void write(char *message);

void init_write(char *message);

void error_write(int errno);

void init_error_write(int errno);
