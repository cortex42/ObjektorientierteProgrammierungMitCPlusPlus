#ifndef RANGE_H
#define RANGE_H

template<typename T>
class IntegralRange {
	public: 
		IntegralRange(T begin_val, T end_val) : begin_val{begin_val}, end_val{end_val} {}
		
		class Iterator{
			public:
				Iterator(T val) : val{val} {}
				T operator*() { return val; }
				Iterator& operator++() {
					++val; return *this;
				}
				Iterator operator++(int) {
					Iterator it = *this;
					++val; return it;
				}
				bool operator==(const Iterator& other) const { return val == other.val; }
				bool operator!=(const Iterator& other) const { return val != other.val; }
				
			private:
				T val;
		};
		
		Iterator begin() const {
			return Iterator(begin_val);
		}
		
		Iterator end() const {
			return Iterator(end_val);
		}
		
	private:
		T begin_val;
		T end_val;
};

#endif //RANGE_H