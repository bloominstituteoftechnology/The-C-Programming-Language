/**
 * PPM functionality
 * 
 * Only type P6 with max RGB value of 255 is supported, currently.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * Write PPM
 * 
 * Returns -1 on error, otherwise 0
 */
int write_ppm(struct ppm *image, char *filename)
{
	// Implement me!
	// Use read_ppm as a model

	return 0;
}

/**
 * Fill an existing PPM with a solid RGB color
 */
void fill_ppm(struct ppm *image, unsigned char *pixel)
{
	// STRETCH GOAL!!!
}

/**
 * Fill a rectangle in an existing PPM with a solid RGB color
 */
void fill_rect_ppm(struct ppm *image, int row, int col, int width, int height, unsigned char *pixel)
{
	// STRETCH GOAL!!!
}

/**
 * Create PPM
 * 
 * Create an empty PPM
 */
struct ppm *create_ppm(int width, int height)
{
	struct ppm *image = malloc(sizeof(struct ppm));

	image->width = width;
	image->height = height;
	image->type = P6; // TODO allow the user to pass this in
	image->maxval = 255;

	int total_bytes = 3 * width * height;

	image->data = malloc(total_bytes);
	memset(image->data, 0, total_bytes); // Clear the image to black

	return image;
}

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

	// TODO handle comment lines

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
unsigned char *get_pixel(struct ppm *image, int col, int row, unsigned char pixel[3])
{
	int index;

	index = (row * image->width * 3) + (col * 3);
	//index = (row * p->width + col) * 3; // same thing

	pixel[0] = image->data[index+0];
	pixel[1] = image->data[index+1];
	pixel[2] = image->data[index+2];

	return image->data + index;
}

/**
 * Put pixel
 */
void put_pixel(struct ppm *image, int row, int col, unsigned char *pixel)
{
	// Implement me!

	// Use get_pixel() as a model
}

/**
 * Stamp an image
 */
void stamp_image(struct ppm *image, struct ppm *dest_image, int dest_row, int dest_col) {

	for (int row = 0; row < image->height; row++) {
		for (int col = 0; col < image->width; col++) {
			unsigned char pixel[3];

			get_pixel(image, row, col, pixel);

			put_pixel(dest_image, row + dest_row, col + dest_col, pixel);
		}
	}
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

	// TODO
	// Parse command line
	// Create new output image
	// Stamp images at the locations specified on the command line
	// Save output image to disk

	return 0;
}

