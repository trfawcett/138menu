#include "gbAlloc.h"

gbAlloc :: gbAlloc()
{
	this->Create();
};

gbAlloc :: ~gbAlloc()
{
	this->FreeMemory();
};

void gbAlloc :: Create()
{
	this->start = NULL;
	this->count = 0;
};

int gbAlloc :: Add(const tData * data)
{
	node * tmp = (node*)malloc(sizeof(node)), * last;
	if(!tmp) return GBALLOC_NO_MEMORY;

	tmp->data = *data;
	tmp->next = NULL;

	if(!this->start)
		this->start = tmp;
	else
	{
		last = this->start;
		while(last->next)
			last = last->next;
		last->next = tmp;
	};
	this->count++;
	return count;
};

tData * gbAlloc :: Get(unsigned index)
{
	node * tmp = this->start;

	if(!start) return NULL;
	for(unsigned i=0;i<index;i++)
	{
		if(!tmp->next) return NULL;
		tmp = tmp->next;
	};
	return &tmp->data;
};

void gbAlloc :: FreeMemory()
{
	if(!this->start) return;
	node * tmp = this->start, * aux;
	while(tmp)
	{
		aux = tmp;
		tmp = tmp->next;
		aux->data.entry->clear();
		delete aux->data.entry;
		free(aux);
	};
	this->Create();
};

int gbAlloc :: GetCount()
{
	return this->count;
};
