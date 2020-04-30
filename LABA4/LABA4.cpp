#include <iostream> 

using namespace std;

struct Tree
{
	int value;
	Tree* right;
	Tree* left;

	Tree()
	{
		value = 0;
		right = NULL;
		left = NULL;
	}
};

struct spis {
	int value;
	spis* pointer;
	spis() {
		value = 0;
		pointer = NULL;
	}
};


void Input(Tree*& el, int v)
{
	if (el == NULL)
	{
		el = new Tree();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}

void Output(Tree* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}

}

void Detach(Tree* root, Tree* el)
{
	if (root == NULL || el == NULL)
	{
		return;
	}
	else if (root->left == el)
	{
		root->left = NULL;
	}
	else if (root->right == el)
	{
		root->right = NULL;
	}
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}
void Remove(Tree* el)
{
	if (el != NULL)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
Tree* Find(Tree* el, int v)
{
	Tree* result = NULL;
	if (el == NULL)
	{
		result = NULL;
	}
	else if (el->value == v)
	{
		result = el;
	}
	else
	{
		result = Find(el->left, v);
		if (result == NULL)
		{
			result = Find(el->right, v);
		}
	}
	return result;
}

int main() {
	Tree* root = NULL;
	spis* first = NULL;
	cout << "Vvedite kolichestvo dereva = ";
	int n, x;
	cin >> n;
	cout << "Vvedite elementi dereva = ";
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Input(root, x);
	}
	cout << endl;
	cout << "Derevo: ";
	Output(root);
	cout << endl;

	int ud;
	cout << endl;
	cout << "VVedite koren kotoriy udaliti = ";
	cin >> ud;
	Tree* e = Find(root, ud);
	Detach(root, e);
	Remove(e);
	cout << endl;
	cout << "Derevo bes kornya: ";
	Output(root);
	cout << endl;

	Tree* e1 = Find(root, ud);
	Detach(root, e1);
	Remove(e1);
	cout << endl;
	cout << endl;
	cout << "Dopolnitelinay proverka " << endl;
	cout << "Derevo bes kornya: ";
	Output(root);
	cout << endl;

	system("pause");
}