#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  //int size;
  std::vector<T> heapItems;
  size_t m_; //ary of the tree aka number of kids
  PComparator c_; // the functor
  void trickleUp(size_t index); 
  void trickleDown(size_t index);





};

// Add implementation of member functions here
template <typename T, typename PComparator>
  void Heap<T, PComparator>::trickleUp(size_t index){
    if(index == 0){
      return;
    }
    
    size_t parent = (index-1)/ m_;
    if ( c_(heapItems[index],heapItems[parent] )){
      std::swap(heapItems[index], heapItems[parent]);
      trickleUp(parent);
    }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t index){
  size_t top = index ;
  //check the children
  for(size_t i= 1; i <= m_; i++ ){
    size_t currChild = m_ * index + i;
    if(currChild < size() && c_(heapItems[currChild], heapItems[top])){
      top = currChild;
    }
  }

  if(index == top){
    return;
  }
  std::swap(heapItems[index], heapItems[top]);
  trickleDown(top);
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapItems[0];
  

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }
  // swap first and last one
  std::swap(heapItems[0], heapItems[size()-1]);
  heapItems.pop_back();
  trickleDown(0);


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heapItems.push_back(item);
  trickleUp(size()-1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
    return heapItems.size();
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c ): m_(m), c_(c){

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}



#endif

