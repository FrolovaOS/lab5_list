#pragma once
using namespace std;
template <class T>

class TList 
{
private:
	struct TNode
	{
		T val;
		TNode *pNext;
		TNode *pPrev;
	};

	TNode *pFict;  
	TNode *pFirst; 
	TNode *pLast;  
	TNode *pCurr;  

public:
	TList();
	TList(const TList<T>& l);
	~TList() ; 
	// 
	T GetVal() { return pCurr->val ;};
	int IsEmpty(); // список пуст ?
	int IsListEnded();
	bool IsLast() { return pCurr == pLast; }; 
// navigation
	void SetCurrentVal(T _val);
	
	void Reset(); 
	void GoNext(); 
	void StepBack(); 
	// ins
	void InsFirst(T _val); 
	void InsLast(T _val); 
	void InsCurrent(T _val); 
	void InsFict(T _val);
	// del
	void DelFirst(); 
	void DelCurrent(); 
	void DelLast();
	void DelList(); 
};



template<class T>
inline TList<T>::TList()
{
	pFirst = pLast =pCurr= pFict=nullptr;
}


template<class T>
TList<T>::TList(const TList<T>& l)
{	
	pFirst = pCurr =pLast= nullptr;
	
	 TNode* tmp = l.pFict;
	InsFict(tmp->val);
	if(l.pFirst!=nullptr)
		tmp = tmp->pNext;
	 while ((tmp != l.pFict)&&(tmp != nullptr))
	 {
		 InsLast(tmp->val);
		 tmp = tmp->pNext;
	 }
}

template<class T>
TList<T>::~TList()
{
		DelList();
}


template<class T>
inline int TList<T>::IsEmpty() 
{
	return pFirst == nullptr;
}



template<class T>
inline int TList<T>::IsListEnded()
{
	return pCurr==pFict;
}

template<class T>
inline void TList<T>::SetCurrentVal(T _val)
{
	
		pCurr->val = _val;
}

template<class T>
inline void TList<T>::Reset(void)
{
	pCurr = pFirst;
}

template<class T>
inline void TList<T>::GoNext(void)
{
	pCurr = pCurr->pNext;
}

template<class T>
inline void TList<T>::StepBack()
{
	pCurr = pCurr->pPrev;
}

template<class T>
inline void TList<T>::InsFirst(T _val)
{
	TNode* p = new TNode;
	p->val = _val;
	if (IsEmpty())
	{	
		p->pNext = pFict;
		p->pPrev = pFict;
		pFirst = pLast =pCurr= p;
		pFict->pNext = p;
		pFict->pPrev = p;
		
	}
	else 
	{
		pFict->pNext = p;
		pFirst->pPrev = p;
		p->pNext = pFirst;
		p->pPrev = pFict;
		pFirst = p;
	}
}

template<class T>
inline void TList<T>::InsLast(T _val)
{
	TNode* p = new TNode;
	p->val = _val;
	if (IsEmpty())
		InsFirst(_val);
	else
	{
		pLast->pNext = p;
		pFict->pPrev = p;
		p->pPrev = pLast;
		p->pNext = pFict;
		pLast = p;
	}
}

template<class T>
inline void TList<T>::InsCurrent(T _val)
{	
	TNode* p = new TNode;
	p->val = _val;

	if ((pCurr == pFirst)||(pFirst==nullptr))
		InsFirst(_val);
	else
	{
		p->pNext = pCurr;
		p->pPrev = pCurr->pPrev;
		pCurr->pPrev = p;

		StepBack();
		StepBack();
		pCurr->pNext = p;
	}
		
}

template<class T>
inline void TList<T>::InsFict(T _val)
{
	pFict = new TNode;
	pFict->val = _val;
	pCurr = pFict;
}

template<class T>
inline void TList<T>::DelFirst(void)
{
	if (!IsEmpty())
	{
		TNode* p = pFirst->pNext;
		delete pFirst;
		pCurr = pFirst = p;
		pCurr->pPrev = pFict;
		pFict->pNext = pCurr;
	}
	else throw "no first node";
}

template<class T>
inline void TList<T>::DelCurrent(void)
{
	TNode* p = pCurr;
	if (pCurr == pFirst) DelFirst();
	else if (pCurr == pLast) DelLast();
	else
	{
		StepBack();

		pCurr->pNext = p->pNext;

		GoNext();

		pCurr->pPrev = p->pPrev;
		delete p;
	}
}

template<class T>
inline void TList<T>::DelLast()
{
	TNode* p = pLast;
	pCurr = pLast;
	StepBack();
	pCurr->pNext = pFict;
	pFict->pPrev = pCurr;
	pLast = pCurr;
	pCurr = pLast->pNext;
	delete p;
}

template<class T>
void TList<T>::DelList()
{
	while ((pFirst != pFict) && (pFirst != nullptr))
	{
		TNode* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	delete pFict;
	pFict=pFirst = pLast = pCurr = nullptr;
}
