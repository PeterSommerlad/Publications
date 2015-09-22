#include <memory>
// contrived example extracted from libstdc++ containers
template<typename _Alloc, typename _Tp>
struct __alloctr_rebind {
	using __type = typename _Alloc::template rebind<_Tp>::other;
};

template<typename _Alloc>
struct allocator_traits {
	template<typename _Tp>
	using _rebind_alloc = typename __alloctr_rebind<_Alloc, _Tp>::__type;
};


template<typename _Alloc>
struct __alloc_traits {
	using _Base_type = allocator_traits<_Alloc>;

	template<typename _Tp>
	struct rebind {
		using other=typename _Base_type::template _rebind_alloc<_Tp>;
	};

};

template<typename F, typename _Alloc>
struct Base {
	using _Tp_alloc_type = typename __alloc_traits<_Alloc>::template
		      rebind<F>::other;
};

template<typename T,typename _Alloc = std::allocator<T> >
struct Stack: Base<T, _Alloc> {
	using _Base = Base <T, _Alloc>;
	using _Tp_alloc_type = typename _Base::_Tp_alloc_type;
    using unnecessary_complex = __alloc_traits<_Tp_alloc_type>;
};

int main() {
	Stack<int> mystack { };
}
