/*
	1. Give an example of a calculation where a Rational gives a mathematically better result than Money.
			Rational r { 22, 7 }; cout << r.to_double(); // outputs 3.14286 accurate result
			Money m { Currency::INR, double(22) / 7 }; cout << m; outputs INR3.14 rounded off to paise

	2. Give an example of a calculation where a Rational gives a mathematically better result than double.
			cout << 0.9999999 * 1; // internally has 0.9999999, outputs 1
			cout << 0.9999999 * 10000000;  // internally has 9999999.0, outputs 1e+071

			cout << Rational {1 / 3} + Rational {1 / 3} + Rational {1 / 3}; // outputs 3/3 so we can have 1.0, 
			// instead of storing 0.999999999999999 in double which could cause problems later 
*/