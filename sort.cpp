#include<iostream>
void bubbleSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	int flag = true;
	for(int i=1;i<length;++i)//time
	{
		flag = true;
		for (int j = 0; j < length - i; ++j)
		{
			if (p[j] > p[j + 1])
			{
				flag = false;
				p[j] = p[j] ^ p[j + 1];
				p[j+1] = p[j] ^ p[j + 1];
				p[j] = p[j] ^ p[j + 1];
			}
		}
		if (flag)
			break;
	}
}

void selectSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	for (int i = 1; i < length; ++i)
	{
		int index = 0;
		for (int j = 1; j <= length - i; ++j)
		{
			if (p[j] > p[index])
				index = j;
		}
		if (index != length - i)
		{
			p[index] = p[index] ^ p[length - i];
			p[length - i] = p[index] ^ p[length - i];
			p[index] = p[index] ^ p[length - i];
		}
	}
}

void insertSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	for (int i = 1; i < length; ++i)
	{
		int val = p[i];
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (p[j] > val)
			{
				p[j + 1] = p[j];
			}
			else
			{
				break;
			}
		}
		p[j + 1] = val;
	}
}

void quickSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	int val = p[0];
	int index = 0;
	for (int i = 1; i < length; ++i)
	{
		if (p[i] < val)
		{
			++index;
			if (index != i)
			{
				p[index] = p[index] ^ p[i];
				p[i] = p[index] ^ p[i];
				p[index] = p[index] ^ p[i];
			}
		}
	}
	if (index != 0)
	{
		p[index] = p[index] ^ p[0];
		p[0] = p[index] ^ p[0];
		p[index] = p[index] ^ p[0];
	}
	quickSort(p, index);
	quickSort(p + index + 1, length - index - 1);
}

void checkToEnd(int *p, int i, int length)
{
	int index = i;
	if (2 * i + 1 < length && p[2 * i + 1] > p[index])
	{
		index = 2 * i + 1;
	}
	if (2 * i + 2 < length && p[2 * i + 2] > p[index])
	{
		index = 2 * i + 2;
	}
	if (index != i)
	{
		p[index] = p[index] ^ p[i];
		p[i] = p[index] ^ p[i];
		p[index] = p[index] ^ p[i];
		checkToEnd(p, index, length);
	}

}

void heapSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	int end = length / 2;
	for (int i = end; i >= 0; --i)
	{
		checkToEnd(p, i, length);
	}

	for (int i = 1; i < length; ++i)
	{
		p[0] = p[0] ^ p[length - i];
		p[length-i] = p[0] ^ p[length - i];
		p[0] = p[0] ^ p[length - i];
		checkToEnd(p, 0, length - i);
	}
}

void mergeTwo(int *p1, int *p2, int len1, int len2)
{
	if (len1 < 1 || len2 < 1)
		return;
	int *p = new int[len1];
	for (int i = 0; i < len1; ++i)
	{
		p[i] = p1[i];
	}
	for (int i = 0, j = 0, k = 0; k < len1 + len2;)
	{
		if (i < len1 && j < len2)
		{
			p1[k++] = p[i] < p2[j] ? p[i++] : p2[j++];
		}
		else
		{
			if (i < len1)
			{
				while (k < len1 + len2)
				{
					p1[k++] = p[i++];
				}
			}
			else
			{
				while (k < len1 + len2)
				{
					p1[k++] = p2[j++];
				}
			}
		}
	}	
}

void mergeSort(int *p, int length)
{
	if (p == NULL || length <= 1)
		return;
	int mid = length / 2;
	mergeSort(p, mid);
	mergeSort(p + mid, length - mid);
	mergeTwo(p, p + mid, mid, length - mid);
}
