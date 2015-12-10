#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

void MergeList(int pseq[],uint pbegin,uint pmiddle,uint pend){
	
	uint beginA = pbegin,beginB = pmiddle + 1,index = 0,pos;
	int *seqTemp = (int *)calloc(pend - pbegin + 1,sizeof(int));
	
	while(beginA <= pmiddle && beginB <= pend){
		if(pseq[beginA] < pseq[beginB]) 
			seqTemp[index++] = pseq[beginA++];
		else 
			seqTemp[index++] = pseq[beginB];
			
		while(beginA <= pmiddle ) seqTemp[index++] = pseq[beginA++];
		while(beginA <= pmiddle ) seqTemp[index++] = pseq[beginB++];
		
		for(pos = 0,beginA = pbegin;pos < index; pos++,beginA++)
			pseq[beginA] = seqTemp[pos];
		free(seqTemp);
	}
}

void MergeSort(int pseq[],uint pbegin,uint pend){
	uint middle;
	if(pbegin < pend){
		middle = ((uint)pbegin + (uint)pend) >> 1;
		MergeSort(pseq,pbegin,middle);
		MergeSort(pseq,middle + 1,pend);
		
		MergeList(pseq,pbegin,middle,pend);
	}
}

int main(int argc, char** argv)
{
	int seq[] = {3,2,1,53,-1};
	MergeSort(seq,0,4);
	uint i;
	for(i = 0; i < 5;i++){
		printf("%d\n",seq[i]);
	}
	
	return 0;
}
