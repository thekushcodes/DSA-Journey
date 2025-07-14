#include <bits/stdc++.h> // Includes all libraries at once
using namespace std;

void explainPair()
{
    pair<int, int> p1 = {1, 2};
    cout << p1.first << " " << p1.second;
    cout << endl;

    pair<int, pair<int, int>> p2 = {1, {1, 2}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second;
    cout << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second;
    cout << endl;
}

void explainVector()
{
    // Vectors are dynamic in nature, i.e., their size can vary according to need. Vector is a container.
    vector<int> v;

    // These two lines add element in vector
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec; // Vector with pair data type
    vec.push_back({1, 2});
    vec.emplace_back(4, 5); // No curly braces

    vector<int> v(5, 100); // Adds '100' 5 times. This is the syntax
    vector<int> v(5);      // Adds 5 empty elements. Values can be 0 or any garbage value

    vector<int> v1(5, 20);
    vector<int> v2(v1); // Creates copy of v1 into v2. Just a copy, so v1 and v2 are separate

    // This is an iterator, which goes through or prints elements of a vector.
    // An iterator returns the memory location so we need to derefernce it like '*it' to get actual value
    vector<int>::iterator it = v.begin(); // .begin() sets pointer to the first element // Also the name of iterator can be anything, here  it is 'it'
    it++;
    cout << *it << endl; // This prints the second element, because we set .begin then it++, so it points to second
    it = it + 2;
    cout << *(it) << endl; // Prints 4th element, as we set it to second previously and now +2 in it.

    // .end() doesnot points to last element, instead it points to the location just after the last element
    vector<int>::iterator it = v.end();
    // .rend() points to the previous location of the first location
    // vector<int> ::iterator it = v.rend(); // Reverse end
    // .rbegin() points to the location of the last element
    // vector<int> :: iterator it = v.rbegin(); // Reverse begin

    cout << v[0] << " " << v.at(0) << endl; // Both prints element at 0th index
    cout << v.back() << endl;

    // Instead of manually printing each element of vector, we can use loops
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << "\n";
    }
    // Below we shortened the syntax by replacing 'vector<int>::iterator' with 'auto'. auto automatically determines the data type.
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << "\n";
    }
    // Below is for-each loop
    for (auto it : v)
    {
        cout << it << endl;
    }

    v.erase(v.begin() + 1);                // Erases element at 1st index, i.e., whatever given in ()
    v.erase(v.begin() + 1, v.begin() + 4); // This erases all elements in the given range of index, also ****[start,end), i.e., start element is erased but the last element that is in range is excluded, only erases upto the element previously to the end range.

    // Insert function
    vector<int> v(2, 100);          // Declared a vector
    v.insert(v.begin(), 300);       // Inserts '300' at the start. (location, value)
    v.insert(v.begin() + 1, 2, 10); // Inserts '10' 2 times at the 2nd index. (location, no. of times, value)

    vector<int> copy(2, 50);                       // Declared a vector named 'copy'
    v.insert(v.begin(), copy.begin(), copy.end()); // Inserts in the start of v and the elements from copy from beginning to end is added

    cout << v.size(); // Returns the number of elements of vector

    v.pop_back(); // Removes the first element

    // v1-->> {10,20}
    // v2-->> {30,40}
    v1.swap(v2); // v1-->> {30,40}, v2-->> {1020}

    v.clear(); // Erases the entire vector

    cout << v.empty(); // Returns 1(True) if v is empty else 0(Flase)
}

void explainList()
{
    // Insert in vector is very costly because it shifts every element, this is efficient in list
    list<int> ls; // Declaared list

    ls.push_back(2); // Adds element '2'
    ls.emplace_back(4);

    ls.push_front(5); // Adds '5' in the beginning of the list

    ls.emplace_front(2, 4);

    // Rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << *(it) << endl;
    }
}

void explainStack()
{
    // LIFO
    stack<int> st; // Declared stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(4); // {4,3,3,2,1}

    cout << st.top(); // Returns the last added element, here 4. Also st[2], i.e., accessing by index is invalid

    st.pop(); // Pops the last added element, now the st.top() is 3

    cout << st.size(); // Return size 4, after popping the element '4'

    cout << st.empty();

    // To swap two stacks
    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue()
{
    // FIFO
    queue<int> q; // Declared queue
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5;     // Adds 5 to the last element, i.e., 4+5=9 // q = {1,2,9}
    cout << q.front(); // Prints 1, i.e., first element

    q.pop(); // Pops the first added element

    // size, swap, empty, are all same as stack
}

void explainPQ()
{
    // Maximum element stays at the top
    priority_queue<int> pq; // Declared Priority Queue
    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.emplace(10); // {10,8,5,2}

    cout << pq.top(); // Prints 10

    pq.pop(); // {8,5,2}

    // size, swap, empty, functions same as others

    // Minimum Heap -->> Stores minimum element at the top
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // Prints 2
}

void explainSet()
{
    // Stores elements in **SORTED way and only **UNIQUE elements are stored
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(1);  // Not inserted in set, only unique values are inserted
    st.emplace(4); // {1,2,3,4}

    // begin, end, rbegin, rend, size, empty and swap are same as those as above
    auto it = st.find(3); // Returns the memory location of element '3'
    auto it = st.find(6); // This will return the next location after the last element, because '6' is not there in the set

    st.erase(5); // Erases the element in (). It taked logarithmic time

    int cnt = st.count(1); // Returns 1 or 0 depending if the element in () is there in set or not, respectively

    auto it = st.find(3); // Location of '3' is sored in 'it'
    st.erase(it);         // This removes the element using it's location. It takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2); // Points to '2'
    auto it2 = st.find(4); // Points to '4'
    st.erase(it1, it2);    // After erasing-> {1,4,5}, because [it1, it2), it2 is excluded, so 2nd and 3rd element will be erased

    // lower_bound() and upper_bound() functions work in the same way as in vector
    // Their syntax:
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

void explainMultiSet()
{
    // Same as set, just we can store multiple occurences of an element. In set we could store unique values only.

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.emplace(1); // {1,1,1}

    ms.erase(1); // Erases all occurences of 1

    int cnt = ms.count(1); // Counts the number of occurences of element in ()

    ms.erase(ms.find(1)); // Erases the value at the given memory address, so even if multiple occurences are there, only the single first element is erased
}

void explainUnorderedSet()
{
    // Same as set, just the elements are not sorted
    unordered_set<int> st;
    // lower and upper bound function does not works
    // It has better complexity in most cases, except some when collision happens
}

void explainMap()
{
    // It stores data in Key:Value pairs. The key must be unique
    // The below piece of code is giving error because same name 'mpp' is used multiple times

    // Declarations of map
    map<int, int> mpp;
    mpp[1] = 2;
    mpp.emplace(3, 4); // inserts key=3, value=4
    mpp.insert({7, 8});

    map<int, pair<int, int>> mpp;
    mpp[1] = {10, 20};
    mpp.emplace(2, (30, 40));
    mpp.insert({4, {70, 80}});

    map<pair<int, int>, int> mpp;
    mpp[{1, 2}] = 100;
    mpp.emplace((3, 4), 200);
    mpp.insert({{7, 8}, 400});

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout << *(it).second << endl;

    auto it = mpp.find(5); // Point to the end+1 location, because no such key

    auto it = lower_bound(2);
    auto it = upper_bound(3);

    // erase, swap, size, empty are same as above.
}

void explainMultiMap()
{
    // Everything is same as map, just it can store multiple keys, so mpp[key] cannot be used here.
}

void explainUnorderedMap()
{
    // same as set and unordered set difference
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
    {
        return true;
    }
    else if (p1.second == p2.second)
    {
        if (p1.first > p2.second)
            return true;
    }
    return false;
}

void explainExtra()
{
    int a[] = {1, 2, 4, 5, 9, 8, 6};
    sort(a, a + n);
    vector<int> v;
    sort(v.begin(), v.end());

    sort(a, a + n, greater<int>); // To sort in descending order

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // What if we want to sort according to second element's ascending order and if same then sort in descending order of first element. For such cases, we make our own comparators, like we made above --> comp()
    sort(a, a + n, comp); // {4,1}, {2,1}, {1,2}

    int num = 7;
    int cnt = __builtin_popcount(num); // Counts the number of '1's in its binary form

    num = 1728373828273;
    long long num = __builtin_popcountll(num);

    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end())); // This prints all the possible permutations after of it like, if we give s = "312", then only it will print -->> "321"

    int maxi = *max_element(a, a + n);
}

int main()
{
    // explainList();

    return 0;
}
