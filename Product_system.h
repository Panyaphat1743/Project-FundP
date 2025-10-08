#ifndef SHOP_H
#define SHOP_H

int find_product_index(const char *id);
int already_added(FILE *file, const char *id);
void run();
#endif