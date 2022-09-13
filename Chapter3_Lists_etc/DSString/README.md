# Using DSVector to Create a String

Since a string is just a vector of characters, it should be straight forward to create a string by extending
`DSVector` for `char`.


```cpp
class DSString : public DSVector<char>
{
    ...
}
```

`DSVector` already provides dynamic memory management and iterators.

