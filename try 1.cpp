#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	
	FILE* in, * out;
	int ch;
	if (argc != 3)
	{
		fprintf(stderr, "请输入cpoyFile 源文件名 目标文件名\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "麻了");
	if (( fopen_s(&in,argv[1], "rb")) == NULL)
	{
		fprintf(stderr,"打不开文件：%s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if (( fopen_s(&out,argv[2], "rb")) == NULL)
	{
		fprintf(stderr, "打不开文件：%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);

	}
	fprintf(stderr, "麻了");
	while ((ch = getc(in)) != EOF)
	{
		if (putc(ch, out) == EOF)
		{
			break;
		}
	}
	if (ferror(in))
	{
		printf("读取文件错误 %s\n", argv[1]);

	}
	if (ferror(out))
	{
		printf("写入文件错误 %s\n", argv[2]);
	}
	printf("复制成功");
	fclose(in);
	fclose(out);

	return 0;
	
}//cin.width()设置输入长度