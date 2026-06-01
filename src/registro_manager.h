#ifndef REGISTRO_MANAGER_H
#define REGISTRO_MANAGER_H

void mcp4132_write_register(uint8_t reg, uint8_t value);

void mcp4132_read_register(uint8_t reg, uint8_t* data);

#endif // REGISTRO_MANAGER_H
