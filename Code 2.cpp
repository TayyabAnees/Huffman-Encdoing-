//#include<iostream>
//#include <vector>
//#include<string>
//#include<fstream>
//using namespace std;
//template<typename T>
//class node
//{
//public:
//	T data;
//	int frequency;
//	node* left;
//	node* right;
//
//	node()
//	{
//		frequency = 0;
//		left = NULL;
//		right = NULL;
//	}
//};
//template<typename T>
//node<T>* newNode(T item, int freq)
//{
//	node<T>* temp = new node<T>();
//	temp->left = temp->right = NULL;
//	temp->data = item;
//	temp->frequency = freq;
//	return temp;
//}
//template<typename T>
//void swap(node<T>** n1, node<T>** n2)
//{
//	node<T>* temp = *n1;
//	*n1 = *n2;
//	*n2 = temp;
//}
//template<typename T>
//class Huffman
//{
//	class MinHeap
//	{
//	public:
//		int size;
//		int capacity;
//		node<T>** array;
//		MinHeap* Make_MinHeap_Helper1(int capacity)
//		{
//			MinHeap* min = (MinHeap*)malloc(sizeof(MinHeap));
//			min->size = 0;
//			min->capacity = capacity;
//			min->array = (node<T>**)malloc(min->capacity * sizeof(node<T>*));
//			return min;
//		}
//		void Heapify(MinHeap* min, int index) {
//			int smallest = index;
//			int left = 2 * index + 1;
//			int right = 2 * index + 2;
//			if (left < min->size && min->array[left]->frequency < min->array[smallest]->frequency)
//				smallest = left;
//			if (right < min->size && min->array[right]->frequency < min->array[smallest]->frequency)
//				smallest = right;
//
//			if (smallest != index)
//			{
//				swap(&min->array[smallest], &min->array[index]);
//				Heapify(min, smallest);
//			}
//		}
//		node<T>* Minimum(MinHeap* min)
//		{
//			node<T>* temp = min->array[0];
//			min->array[0] = min->array[min->size - 1];
//			--min->size;
//			Heapify(min, 0);
//			return temp;
//		}
//		void insert(MinHeap* min, node<T>* heap_node)
//		{
//			++min->size;
//			int i = min->size - 1;
//			while (i && heap_node->frequency < min->array[(i - 1) / 2]->frequency) {
//				min->array[i] = min->array[(i - 1) / 2];
//				i = (i - 1) / 2;
//			}
//			min->array[i] = heap_node;
//		}
//		MinHeap* Creating_Heap(vector<T> item, vector<int> freq, int size)
//		{
//			MinHeap* min = Make_MinHeap_Helper1(size);
//			for (int i = 0; i < size; ++i)
//				min->array[i] = newNode(item[i], freq[i]);
//			min->size = size;
//			int n = min->size - 1;
//			int i;
//			for (i = (n - 1) / 2; i >= 0; --i)
//				Heapify(min, i);
//
//			return min;
//		}
//		node<T>* Huffman_Tree(vector<T> item, vector<int> freq, int size)
//		{
//			node<T>* left;
//			node<T>* top;
//			node<T>* right;
//			MinHeap* min = Creating_Heap(item, freq, size);
//			while (min->size != 1)
//			{
//				left = Minimum(min);
//				right = Minimum(min);
//				string a = "@";
//				top = newNode(a, left->frequency + right->frequency);
//				top->left = left;
//				top->right = right;
//				insert(min, top);
//			}
//			return Minimum(min);
//		}
//	};
//public:
//	vector<string>encode;
//	vector<string>characters;
//	vector<T>decode;
//	void encode_(node<T>* root, string a)
//	{
//		if (root == NULL)
//		{
//			return;
//		}
//		encode_(root->left, a + "0");
//		if (root->data != "@")
//		{
//			characters.push_back(root->data);
//			encode.push_back(a);
//			a = "";
//		}
//		encode_(root->right, a + "1");
//	}
//	void encoding()
//	{
//		string text;
//		ifstream fin;
//		ofstream fout;
//		fin.open("text_to_bin.txt");
//		fout.open("bin_to_bin.txt");
//		while (!fin.eof())
//		{
//			string bit = "";
//			int count = 0;
//			int j = 0;
//			while (count < 50)
//			{
//				char a;
//				fin >> a;
//				if (a == '\n')
//					fout << "\n";
//				if (!fin.eof())
//				bit = bit + a;
//				count++;
//			}
//
//			for (; j < characters.size(); j++)
//			{
//			  if (characters[j] == bit)
//					{
//						break;
//					}
//			}
//				fout << encode[j];
//		}
//		fin.close();
//		fout.close();
//	}
//	node<T>* Huffman_Codes(vector<T> item, vector<int> freq, int size)
//	{
//		MinHeap obj;
//		node<T>* root = obj.Huffman_Tree(item, freq, size);
//		encode_(root, "");
//		return root;
//	}
//	void inorder(node<T>* root)
//	{
//		if (root == NULL)
//			return;
//		cout << root->data << " ";
//		inorder(root->left);
//		inorder(root->right);
//
//	}
//	void decode_file(node<T>* root)
//	{
//		fstream fin;
//		fin.open("bin_to_bin.txt");
//		while (!fin.eof())
//		{
//			string s;
//			getline(fin, s);
//			string ans = "";
//			node<T>* curr = root;
//			for (int i = 0; i < s.size(); i++) {
//				if (s[i] == '0')
//					curr = curr->left;
//				else if (s[i] == '1')
//					curr = curr->right;
//
//				if (curr->data != "@")
//				{
//					ans += curr->data;
//					curr = root;
//				}
//			}
//			cout << ans << endl;
//		}
//	}
//
//};
//int main()
//{
//	vector<string> v;
//	string text;
//	ifstream file;
//	file.open("text_to_bin.txt");
//	while (!file.eof())
//	{
//		string bit="";
//		int count = 0;
//		while (count < 50)
//		{
//			char a;
//			file >> a;
//			if(!file.eof())
//			bit = bit + a;
//			count++;
//		}
//		v.push_back(bit);
//	
//	}
//	vector<node<string>*> vr;
//	for (int i = 0; i < v.size(); i++)
//	{
//		node<string>* n = new node<string>();
//		n->data = v[i];
//		n->frequency = 1;
//		bool check = true;
//		for (int j = 0; j < vr.size(); j++)
//		{
//			if (n->data == vr[j]->data)
//			{
//				vr[j]->frequency++;
//				check = false;
//			}
//		}
//		if (check)
//		{
//			vr.push_back(n);
//		}
//	}
//	vector<int> f;
//	vector<string> itm;
//	for (int i = 0; i < vr.size(); i++)
//	{
//		cout << vr[i]->data << "  " << vr[i]->frequency << endl;
//		f.push_back(vr[i]->frequency);
//		itm.push_back(vr[i]->data);
//	}
//	Huffman<string> obj;
//	node<string>* text_root = obj.Huffman_Codes(itm, f,itm.size());
//
//	for (int i = 0; i < obj.encode.size(); i++)
//	{
//		cout << obj.characters[i] << " : " << obj.encode[i] << endl;
//	}
//	cout << obj.characters.size() << " : " << obj.encode.size();
//	obj.encoding();
//	cout << "===========================================DECODED Binary===========================================" << endl;
//	obj.decode_file(text_root); 
//
//	return 0;
//}
