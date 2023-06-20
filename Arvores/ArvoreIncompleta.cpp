#include <queue>
#include <iostream>

using namespace std;

template<class T>
class ArvoreNo {
	public:
		T el;
		ArvoreNo<T> *left, *right;
		ArvoreNo() {
			left = right = 0;			
		}

		ArvoreNo(T e, ArvoreNo<T> *l=0, ArvoreNo<T> *r = 0){
			el = e;
			left = l;
			right = r;
		}
};

template<class T>
class Arvore {
	protected:
		ArvoreNo<T> *root;

	public:
		Arvore() {
			root = 0;			
		}

		~Arvore() {
			clear();
		}

		void clear() {
			clear(root);
			root = 0;
		}
		
		ArvoreNo<T>* getRoot() {
			return root;
		}

		bool isEmpty() const {
		   return root = 0;
		}
		   
		void visit(ArvoreNo<T> *p) {
			cout << p->el << " ";
		} 
		
		T search(T el) {
			ArvoreNo<T> *p = root;

			while (p != 0) {
				
				if (el == p->el)		
					return p->el;								    
				else {
					if (el < p->el)
				       p = p->left;
				    else p = p->right;
			 	}
		    }

			return 0;
		}

		//obs: pg 209 figura 6.23
		void insert(T el) {
			ArvoreNo<T> *p = root, *prev = 0;

			while (p != 0) {
				prev = p;

				if (el < p->el)
					p = p->left;
				else p = p->right;
			}

			if (root == 0) //a arvore esta vazia
			    root = new ArvoreNo<T>(el);
			else if (el < prev->el)
				prev->left = new ArvoreNo<T>(el);
			else prev->right = new ArvoreNo<T>(el);
			}

		void percusoExtensao() {
			if (p != 0) {
                visit(p);
                percusoExtensao(p-> )
            }
		}

		void preorder(ArvoreNo<T> *p){
			if (p != 0) {
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
			
		}
	
};

main(){
	
	Arvore<int> *a=new Arvore<int>();
	a->insert(13);
	a->insert(10);	
	a->insert(25);	
	a->insert(2);	
	a->insert(12);
	a->insert(20);
    a->insert(31);
    a->insert(29);

    //	a->percusoExtensao();
    //	a->preorder(a->getRoot());

	int procurado = a->search(200);
	if (procurado == 0)
	    cout << "Nao achou ";
	else
	    cout << procurado << " encontrado!!";
}
