#include <stdio.h>

int main() 
{
	FILE *fp, *ftemp;
	fp = fopen("student_list.txt", "a");
	ftemp = fopen("temp.txt", "w+");
	char c, temp, buff[100];
	c = getc(fp);
	while (c != EOF) {
		if (c == '3') {
			//temp = '\0';
			//printf("%c", c);
			c = getc(fp);
			if(c == '2') {
				//fputc( temp, fp);
				//printf("%c", c);
				printf("%ld", ftell(fp));
				fseek(fp, 2, ftell(fp));
				temp = ftell(fp);
				while (c != '\n') {
					c = getc(fp);
				}					
				break;
			}
		}
		c = getc(fp);
	}
	fseek(fp, 0, ftell(fp));
	c = getc(fp);
	printf("\n");
	while (c != EOF) {
		printf("%c", c);
	fprintf(ftemp, "%c", c);
		c = getc(fp);
	}
	fprintf(fp, "%c", c);
	c = getc(ftemp);
	//rewind(fp);
	rewind(ftemp);
	c = getc(ftemp);
	printf("pos %ld", ftell(fp));
	while ( c != EOF) {
		fprintf(fp, "%c", c);
		c = getc(ftemp);
	
	}

    fclose(fp);
    fclose(ftemp);

}

