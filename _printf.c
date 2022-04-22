#include "main.h"

int _printf(char *format, ...)
{
	int i;
	int count;
	int state;
	va_list ap;
	va_start(ap, format);
	/char buffer[100];/

		 count = 0;
		 state = 0;
		 i = 0;

		 while (format && format[i])
		 {
			 if (state == 0)
			 {
				 if (*format != '%' && *format != '\n')
				 {
					 _putchar(*format);
					 count++;
				 }
				 else if (*format == '\n')
				 {
					 putchar('\n');
					 count++;
				 }

				 else
				 {
					 state = 1;
				 }
			 }
			 else if (state == 1)
			 {
				 switch (*format)
				 {
				 case 's':
				 {
					 char *str = va_arg(ap, char *);
					 /_puts(str);/
						  while (*str)
						  {
							  _putchar(*str++);
							  count++;
						  }
						  break;
				 }
				 case 'c':
				 {
					 int ch = va_arg(ap, int);
					 _putchar(ch);
					 count++;
					 break;
				 }
				 case 'd':
				 {
					 int ch = va_arg(ap, int);
					 char buff[100];
					 char *buff1 = itoa(ch, buff, 10);
					 while (*buff1)
					 {
						 count++;
						 putchar(*buff1++);
					 }

					 break;
				 }
				 case 'i':
				 {
					 int ch = va_arg(ap, int);
					 char buff[100];
					 char *buff1 = itoa(ch, buff, 10);
					 while (*buff1)
					 {
						 count++;
						 putchar(*buff1++);
					 }

					 break;
				 }
				 case '%':
				 {

					 _putchar('%');
					 count++;
					 break;
				 }
				 }
				 state = 0;
			 }

			 format++;
		 }
		 va_end(ap);

		 return (count);
}
