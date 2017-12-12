#include <stdio.h>
#include <stdlib.h>

#define P3 3
#define P6 6

struct ppm {
	int type;
	int width;
	int height;
	int maxval;
	unsigned char *data;
};

/**
 * Read PPM
 */
struct ppm *read_ppm(char *filename)
{
	FILE *fp;
	char buffer[128];
	int width, height;
	struct ppm *ppm;

	fp = fopen(filename, "rb");

	if (fp == NULL) {
		return NULL;
	}

	// Read the magic number
	fgets(buffer, sizeof buffer, fp);

	// TODO check to see what the magic number is and do the right thing
	// Assume it's P6 for now

	// Read the width and height
	fgets(buffer, sizeof buffer, fp);
	sscanf(buffer, "%d %d", &width, &height);

	int total_bytes = 3 * width * height;

	// Read the max pixel value
	fgets(buffer, sizeof buffer, fp);

	// TODO do the right thing with this
	// Assume it's 255 for now

	// Allocate a new PPM struct
	ppm = malloc(sizeof(struct ppm));
	ppm->width = width;
	ppm->height = height;

	// Allocate room for the data
	ppm->data = malloc(total_bytes);

	// Read data into the data buffer
	int bytes_read = fread(ppm->data, 1, total_bytes, fp);

	if (bytes_read != total_bytes) {
		fprintf(stderr, "only read %d/%d bytes", bytes_read, total_bytes);
	}

	return ppm;
}

/**
 * Deallocate a ppm
 */
void free_ppm(struct ppm *p)
{
	free(p->data);
	free(p);
}

/**
 * Get pixel
 */
unsigned char *get_pixel(struct ppm *p, int col, int row, unsigned char pixel[3])
{
	int index;

	index = (row * p->width * 3) + (col * 3);
	//index = (row * p->width + col) * 3; // same thing

	pixel[0] = p->data[index+0];
	pixel[1] = p->data[index+1];
	pixel[2] = p->data[index+2];

	// memcpy(pixel, p->data + index, 3); // same as above

	return p->data + index;
}

/**
 * MAIN
 */
int main(void)
{
	struct ppm *p = read_ppm("vim.ppm");
	unsigned char pixel[3] = {0,0,0};

	get_pixel(p, 20, 20, pixel);

	printf("pixel is %u, %u, %u\n", pixel[0], pixel[1], pixel[2]);

	return 0;
}

