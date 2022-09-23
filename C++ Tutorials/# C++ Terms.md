# C++ Terms

**char_traits or Trait:** The char_traits is a traits class template that abstracts basic character and string operations for a given character type. 

    - The defined opearation set is such that generic algorithms almost always can be implemented in terms of customized char_traits class.

    - it is possible to use such algorithms with almost any possible character or string type, just by supplying a customized char_traits class.

    - The char_traits class template serves as a bassic for explicit instantiations. the user can provide a specialization for any custom character types. Several specializations are defined for the standard charcter types.

    Note: if an operation traits emits an exception, the behavior is undefined.


