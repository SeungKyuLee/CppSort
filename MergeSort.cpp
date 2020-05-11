/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*  
* name   : MergeSort.cpp
* author : LeeSK
* Version: V.1.0
* desc   : The first version of MergeSort (only int type) MergeSort
*/
#include <vector>
#include <iostream>

using namespace std;

//typedef returnType(*name)(arguments);                       // All
//using name = returnType(*)(arguments);                      // <= C++11
//using name = std::add_pointer<returnType(arguments)>::type; // <= C++11
//using name = std::add_pointer_t<returnType(arguments)>;     // <= C++14

using _Pred = bool(*)(int, int);

class MergeSort
{
public:
  /* constructor */
  MergeSort ()
  {
  }
  MergeSort (vector<int> numVector)
  {
    m_Numbers.assign (numVector.begin (), numVector.end ());
    m_NumOfNumbers = m_Numbers.size ();
  }
  
  // set private vector member
  void SetVectorMember(vector<int> &numVector)
  {
    m_Numbers.assign(numVector.begin (), numVector.end ());
    m_NumOfNumbers = m_Numbers.size ();
  }
  
  // Print Values
  void PrintNumbers()
  {
      for(auto num : m_Numbers)
      {
          cout << num << ' ';
      }
      cout << endl;
  }
  
  //Do MergeSort
  void DoMergeSort()
  {
    int left = 0;
    int right = m_NumOfNumbers - 1;
    DividePart(left, right);
  }
  
  // Merge
  void MergePart (int left, int mid, int right);
  void DividePart (int left, int right);
private:
  vector<int> m_Numbers;
  int m_NumOfNumbers;
  _Pred _pred;
};

/* Merge Two Parts */
void
MergeSort::MergePart (int left, int mid, int right)
{
  int l = left;
  int r = mid + 1;
  int m = mid;
  vector < int >tmpBuffer;


  while (l <= mid && r <= right)
    {
      if (m_Numbers[l] < m_Numbers[r])
	{
	  tmpBuffer.push_back (m_Numbers[l++]);
	}
      else
	tmpBuffer.push_back (m_Numbers[r++]);
    }

  if (l <= mid)
    {
      for (int i = l; i <= mid; i++)
	tmpBuffer.push_back (m_Numbers[i]);

    }
  else
    {
      for (int i = r; i <= right; i++)
	{
	  tmpBuffer.push_back (m_Numbers[i]);
	}
    }

  //copy from tmpBuffer vector to original class member vector
  for (int i = left; i <= right; i++)
    {
      m_Numbers[i] = tmpBuffer[i - left];
    }
}

/* Split Each Parts ==> Continuing Split (recursion) */
void
MergeSort::DividePart (int left, int right)
{
  int mid;
  // base case (left == right)
  if (left < right)
    {
      mid = (left + right) / 2;
      DividePart (left, mid);
      DividePart (mid + 1, right);
      MergePart (left, mid, right);
    }
}

int
main ()
{
    vector<int> numbers;
    MergeSort mergeSort;
    
    /* Example */
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(9);
    numbers.push_back(40);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(99);
    
    mergeSort.SetVectorMember(numbers);
    
    cout << "Before Merge Sort" << endl;
    mergeSort.PrintNumbers();
    
    cout << "After Merge Sort" << endl;
    mergeSort.DoMergeSort();
    mergeSort.PrintNumbers();
    
    return 0;
}
