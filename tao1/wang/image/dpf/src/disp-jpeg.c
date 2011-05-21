#include "common.h"
int display_jpeg(char *filename, fb_info fb_inf)
{

	fb_info jpeg_inf;
	
	u8_t *buf24 = decode_jpeg(filename, &jpeg_inf);
	u8_t * scale_buf = scale24(buf24, fb_inf, jpeg_inf);
	u32_t *buf32 = rgb24to32(scale_buf, fb_inf);

	int i, j;
	for(i = 0; i < fb_inf.h;  ++i)
	{
		for (j = 0; j < fb_inf.w; ++j)
		{
				fb_pixel(fb_inf, j, i, buf32[j + i * fb_inf.w]);
		}

	}

	free(buf24);
	free(scale_buf);
	free(buf32);
	
	return 0;
}
