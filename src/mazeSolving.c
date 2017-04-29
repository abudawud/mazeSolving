#include <stdio.h>
#include <string.h>

char elim(char * data){
	if( strncmp(data, "LUL", 3) == 0)
		return 'S';
	else if( strncmp(data, "RUR", 3) == 0)
		return 'S';
	else if( strncmp(data, "LUS", 3) == 0)
		return 'R';
	else if( strncmp(data, "RUS", 3) == 0)
		return 'L';
	else if( strncmp(data, "RUL", 3) == 0)
		return 'U';
	else if( strncmp(data, "LUR", 3) == 0)
		return 'U';
	else if( strncmp(data, "SUS", 3) == 0)
		return 'U';
	else if( strncmp(data, "SUL", 3) == 0)
		return 'R';
	else if( strncmp(data, "SUR", 3) == 0)
		return 'L';
	else
		printf("{FAIL}");

}
int parse(char *data, int step, char * res){
	char * mask, stat;
	unsigned char sub;
	int i, j;
	i = j = 0;

	mask = data;

	while((mask - data) < step){
		if(mask[1] == 'U' && (mask + 3 - data) <= step){
			printf("\t%c%c%c", mask[0], mask[1], mask[2]);
			sub = elim(mask);
			printf("(%c)\t", sub);
			res[i++] = sub;
			mask += 3;
		}
		else{
			printf("%c", *mask);
			res[i++] = *mask;
			mask++;

		}
	}
	res[i] = '\0';
	return i;
	printf("\n");
}

int ublok(char * data, int size){
	while(size-- > 0){
		if (data[size] == 'U')
			return 1;
	}
	return 0;
}

void inverse(char * data, char * res, int size){
	int i = 0;

	while(size-- > 0){
		printf("[%c]", data[size]);
		if (data[size] == 'R')
			res[i] = 'L';
		else if(data[size] == 'L')
			res[i] = 'R';
		else
			res[i] = data[size];
		i++;
	}

	res[i] = '\0';
}
int main(){
	char path[20];
	char fpath[20], rhome[10];

	char * ptr;
	int step, i;

	printf("Input Path: ");
	scanf("%s", path);
	printf("Path Steps: ");
	scanf("%d", &i);
	ptr = path;
//	elim("SULL");
	while(ublok(ptr, i) == 1){
		printf("\n\nPath : %s\n", ptr);
		printf("Parse: ");
		i = parse(ptr, i, fpath);
		ptr = fpath;
	}

	inverse(ptr, rhome, i);
	printf("\n\nFastest Path : %s\n", ptr);
	printf("Return Home  : %s", rhome);
	return 0;
}
