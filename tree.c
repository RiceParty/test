#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
struct TreeNode
{
	T m_iValue;
	TreeNode *m_pLeft;
	TreeNode *m_pRight;
};

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree(void);
	TreeNode<T>* CreateTree();
	void DeleteTree(TreeNode<T>* node);
	void PreOrder(TreeNode<T>* node);
	void InsertNode(TreeNode<T>* newNode,TreeNode<T>* faNode);
	void InOrder(TreeNode<T>* node);
	void PostOrder(TreeNode<T>* node);
	TreeNode<T>* root;
	void FindReverseMaxK(TreeNode<T>* node,int k);
	int size;
};

template<typename T>
BinaryTree<T>::BinaryTree():size(0)
{
	this->root=CreateTree();
}

template<typename T>
BinaryTree<T>::~BinaryTree(void)
{
	DeleteTree(root);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::CreateTree()
{
	TreeNode<T> *node;
	T value;
	cout<<"enter root value:";
	cin>>value;
	node=new TreeNode<T>;
	node->m_iValue=value;
	node->m_pLeft=NULL;
	node->m_pRight=NULL;
	return node;
}

template<typename T>
void BinaryTree<T>::InsertNode(TreeNode<T>* newNode,TreeNode<T>* faNode)
{
	if(newNode->m_iValue > faNode->m_iValue)
	{
		if(faNode->m_pRight==NULL)
			faNode->m_pRight=newNode;
		else
			InsertNode(newNode,faNode->m_pRight);
	}
	else if(newNode->m_iValue < faNode->m_iValue)
	{
		if(faNode->m_pLeft==NULL)
			faNode->m_pLeft=newNode;
	else
			InsertNode(newNode,faNode->m_pLeft);
	}
	else
		cout<<"same value"<<endl;
}

template<typename T>
void BinaryTree<T>::DeleteTree(TreeNode<T> *root)
{
	if(root!=NULL)
	{
		DeleteTree(root->m_pLeft);
		DeleteTree(root->m_pRight);
		delete root;
	}
}

template<typename T>
void BinaryTree<T>::PreOrder(TreeNode<T>* root)
{
	if(root!=NULL)
	{
		cout<<root->m_iValue<<" ";
		PreOrder(root->m_pLeft);
		PreOrder(root->m_pRight);
	}
	else
		return;
}

template<typename T>
void BinaryTree<T>::InOrder(TreeNode<T>* node)
{
	if(node!=NULL)
	{
		InOrder(node->m_pLeft);
		cout<<node->m_iValue<<" ";
		InOrder(node->m_pRight);
	}
	else
		return;
}

template<typename T>
void BinaryTree<T>::PostOrder(TreeNode<T>* node)
{
	if(node!=NULL)
	{
		PostOrder(node->m_pLeft);
		PostOrder(node->m_pRight);
		cout<<node->m_iValue<<" ";
	}
	else
		return;
}

template<typename T>
void Mirror(TreeNode<T>* node)
{
	if(node==NULL) return;
	
	TreeNode<T>* tmp;
	tmp=node->m_pLeft;
	node->m_pLeft=node->m_pRight;
	node->m_pRight=tmp;

	if(node->m_pLeft)
		Mirror(node->m_pLeft);

	if(node->m_pRight)
		Mirror(node->m_pRight);
}

template<typename T>
void NorInOrder(TreeNode<T>* node)
{
	TreeNode<T>* currentnode=node;
	stack<TreeNode<T>*> s;
	while(1)
	{
		while(currentnode)
		{
			s.push(currentnode);
			currentnode=currentnode->m_pLeft;
		}
		if(s.empty())	return;
		currentnode=s.top();
		s.pop();
		cout<<currentnode->m_iValue<<" ";
		currentnode=currentnode->m_pRight;
	}
}

template<typename T>
void NorPreOrder(TreeNode<T>* node)
{
	TreeNode<T>* currentnode=node;
	stack<TreeNode<T>*> s;
	while(1)
	{
		while(currentnode)
		{
			cout<<currentnode->m_iValue<<" ";
			s.push(currentnode);
		currentnode=currentnode->m_pLeft;
		}
		if(s.empty()) return;
		currentnode=s.top();
		s.pop();
		currentnode=currentnode->m_pRight;
	}
}

template<typename T>
void LevelOrder(TreeNode<T>* node)
{
	TreeNode<T>* currentnode=node;
	queue<TreeNode<T>*> q;
	while(currentnode)
	{
		cout<<currentnode->m_iValue<<" ";
		if(currentnode->m_pLeft) q.push(currentnode->m_pLeft);
		if(currentnode->m_pRight) q.push(currentnode->m_pRight);
		if(q.empty()) return;
		currentnode=q.front();
		q.pop();
	}
}

template<typename T>
void BinaryTree<T>::FindReverseMaxK(TreeNode<T>* node,int k)
{
	TreeNode<T>* currentnode=node;
	stack<TreeNode<T>*> s;
	while(k--)
	{
		while(currentnode)
		{
			s.push(currentnode);
			currentnode=currentnode->m_pRight;
		}
		if(s.empty()) return;
		currentnode=s.top();
		s.pop();
		if(!k)
			cout<<currentnode->m_iValue<<" ";
		currentnode=currentnode->m_pLeft;
	}
}

int main()
{
	BinaryTree<int> t;
	int value;
	cout<<"enter new node value ('-1' means quit insert):"<<endl;
	while(cin>>value&&value!=-1)
	{
		TreeNode<int>* node;
		node=new TreeNode<int>;
		node->m_iValue=value;
		node->m_pLeft=NULL;
		node->m_pRight=NULL;
		t.InsertNode(node,t.root);
	}
	cout<<"preorder:"<<endl;
	t.PreOrder(t.root);
	cout<<endl;
	cout<<"inorder:"<<endl;
	t.InOrder(t.root);
	cout<<endl;
	cout<<"postorder:"<<endl;
	t.PostOrder(t.root);
	cout<<endl;
	cout<<"levelorder:"<<endl;
	LevelOrder(t.root);
	cout<<endl;


	cout<<"Nor PreOrder"<<endl;
	NorPreOrder(t.root);
	cout<<endl;
	cout<<"Nor InOrder:"<<endl;
	NorInOrder(t.root);
	cout<<endl;
//	cout<<"Nor PostOrder:"<<endl;
//	NorPostOrder(t.root);
//	cout<<endl;

	int k;
	cout<<"reverse find max k:"<<endl;
	while(cin>>k&&k!=-1)
	{
		t.FindReverseMaxK(t.root,k);
		cout<<endl;
	}
	cout<<endl;

	Mirror(t.root);
	cout<<"Mirror tree:"<<endl;
	t.PreOrder(t.root);
	cout<<endl;

	return 0;
}
