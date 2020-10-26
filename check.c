#include "holberton.h"
/**
 * checker - It checks for any match with the format.
 * @fmt: Format to check.
 * @flag: Flag for check.
 * @fmtF: Array of structures.
 * @fm: Variadic Function Lists.
 *
 * Return: It returns characters.
 */
int checker(format fmt, int flag, struct tFormat fmtF[], va_list fm)
{
	int i, j, ou;

	i = ou = j = 0;
	while ((fmt && *(fmt + i)))
	{
		if ((*(fmt + i) != '%') && flag == 0)
			ou += print_main(*(fmt + i));
		else
		{
			while (j < 12)
			{
				if (((*(fmt + i + 1)) == fmtF[j].id[1]) && flag == 0)
				{
					ou += (fmtF[j].f)(fm, checkBase(*(fmt + i + 1)),
							(*(fmt + i + 1) == 'X' ? 32 : 0)), j = 0, flag = 1;
					break;
				}
				if (j == 11 && flag == 0)
				{
					if ((*(fmt + i + 1)))
						ou += print_main(*(fmt + i));
					else
					{
						ou = -1, flag = 1, j = 0;
						break;
					}
				}
				if (flag == 1)
				{
					flag = 0;
					break;
				}
				j++;
			}
		}
		j = 0, i++;
	}
	va_end(fm);
	return (ou);
}

/**
* checkBase - Check what base choose.
* @fmt: Format selected.
*
* Return: Base of number.
*/
int checkBase(char fmt)
{
	return (fmt == 'b' ? 2 :
		fmt == 'o' ? 8 :
		fmt == 'x' ? 16 :
		fmt == 'X' ? 16 :
		10);
}
