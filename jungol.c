#include <stdio.h>

int main()
{
	int test_case;
	int N;

	scanf("%d%*c", &N);
	for (test_case = 0; test_case < N; test_case++)
	{
		char* arr;
		int length;
		int i, j;
		char ch;
		int count = 0;

		int point = 0;

		scanf("%d%*c", &length);

		arr = malloc(length * length);

		for (i = 0; i < length * length; i++)
		{
			scanf("%c%*c", &ch);
			arr[i] = ch;
		}

		int x_pos = 1;
		int h_count = 1;
		int z;
		int shot = 0;
		int ro = length;

		for (i = 0; i < length; i++)
		{
			for (j = 0; j < length; j++)
			{
				//X를 발견하면
				if (arr[count] == 'X')
				{
					
					for (shot = 0; shot < 4; shot++)
					{
						//좌로 이동
						if (shot == 0)
						{
							for (z = 0; z < j; z++)
							{
								if (arr[count - z] == 'Y')
								{

									break;
								}
								else if (arr[count - z] == 'H')
								{
									if (h_count == 2)
									{
										h_count = 1;
										point++;
									}
									h_count++;
								}
							}
						}
						
						else if (shot == 1)
						{
							//우로 이동
							for (z = 0; z < ro - j; z++)
							{
								if (arr[count + z] == 'Y')
								{

									break;
								}
								else if (arr[count + z] == 'H')
								{
									if (h_count == 2)
									{
										h_count = 1;
										point++;
									}
									h_count++;

								}
							}
						}
						
						else if (shot == 2)
						{
							//하로 이동
							for (z = (i * length) + j; z < length * length; z+=length)
							{
								if (arr[count + z] == 'Y')
								{

									break;
								}
								else if (arr[count + z] == 'H')
								{
									if (h_count == 2)
									{
										h_count = 1;
										point++;
									}
									h_count++;

								}
							}
						}

						else if (shot == 3)
						{
							//상으로 이동
							for (z = 0; z < (i * length) + j; z += length)
							{
								if (arr[count - z] == 'Y')
								{

									break;
								}
								else if (arr[count - z] == 'H')
								{
									if (h_count == 2)
									{
										h_count = 1;
										point++;
									}
									h_count++;
								}
							}
						}
					}
					

					
				}
				//X를 발견하면
				count++;
			}
		}

		printf("#%d %d\n", test_case + 1, point);

		free(arr);
	}
	

	return 0;
}