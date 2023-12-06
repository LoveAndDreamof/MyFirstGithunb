#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	
	FILE* in, * out;
	int ch;
	if (argc != 3)
	{
		fprintf(stderr, "������cpoyFile Դ�ļ��� Ŀ���ļ���\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "����");
	if (( fopen_s(&in,argv[1], "rb")) == NULL)
	{
		fprintf(stderr,"�򲻿��ļ���%s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if (( fopen_s(&out,argv[2], "rb")) == NULL)
	{
		fprintf(stderr, "�򲻿��ļ���%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);

	}
	fprintf(stderr, "����");
	while ((ch = getc(in)) != EOF)
	{
		if (putc(ch, out) == EOF)
		{
			break;
		}
	}
	if (ferror(in))
	{
		printf("��ȡ�ļ����� %s\n", argv[1]);

	}
	if (ferror(out))
	{
		printf("д���ļ����� %s\n", argv[2]);
	}
	printf("���Ƴɹ�");
	fclose(in);
	fclose(out);

	return 0;
	
}//cin.width()�������볤��