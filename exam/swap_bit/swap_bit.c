unsigned	char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned char x = 0b10110010;
// 	unsigned char swapped = swap_bits(x);
// 	printf("Before: %02X\n", x);
// 	printf("After:  %02X\n", swapped);
// }