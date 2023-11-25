#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ParsedData {
  uint8_t header;
  char *payload;
};

void parse_buffer(uint8_t *buffer, struct ParsedData *parsed_data) {
  parsed_data->header = buffer[0];
  parsed_data->payload = (char *)&buffer[1];
};

void get_data(uint8_t *buffer) {
  const uint8_t data[] = {255, 't', 'e', 's', 't'};
  memcpy(buffer, data, sizeof(data));
}

int main(void) {
  // Alloc buffer for received data
  uint8_t *buffer = malloc(1024); // We'll ignore if the pointer is NULL

  // Simulate getting data from somewhere else (Ex: Socket)
  get_data(buffer);

  // Parse buffer into ParsedData struct
  struct ParsedData parsed_data;
  parse_buffer(buffer, &parsed_data);

  // Print payload content
  printf("%s\n", parsed_data.payload);

 // Print payload content
  printf("Original: %s\n", parsed_data.payload);

  // Tamper with the original buffer
  buffer[1] = 'j';

  // Print payload content
  printf("Tampered: %s\n", parsed_data.payload);


  // Print payload content
  printf("Freed: %s\n", parsed_data.payload);

  free(buffer);

  return 0;
}