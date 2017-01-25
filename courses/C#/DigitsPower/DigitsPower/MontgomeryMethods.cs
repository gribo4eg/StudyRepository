using System;
using System.Numerics;
using static System.Math;
using static DigitsPower.HelpMethods;



namespace DigitsPower
{
    public static class MontgomeryMethods
    {
        public static BigInteger MontgomeryMultDomain(BigInteger a, BigInteger b, BigInteger N, MyList<BigInteger> parameters)
        {
            BigInteger result = a * b;
            result = (result + ((result * parameters[0]) & parameters[1]) * N) >> (int)parameters[2];
            if (result >= N)
                result -= N;

            return result;
        }
        public static MyList<BigInteger> toMontgomeryDomain(ref BigInteger a, ref BigInteger b, BigInteger N)
        {
            String n_str = ConvToBinary(N);
            int m = n_str.Length;
            BigInteger r = 1 << m;
            BigInteger r_inv = Euclid_2_1(N, r);
            BigInteger n_shtrih = (r * r_inv - 1) / N;
            BigInteger b_module = r - 1; // маска для виконання операцій за модулем b  

            MyList<BigInteger> result = new MyList<BigInteger>();
            result.Add(n_shtrih);
            result.Add(b_module);
            result.Add(m);
            result.Add(r_inv);


            /*
            // обчислення a_Montgomery (a = a * r % N)
            a = a * r % N;
            // обчислення b_Montgomery (b = b * r % N)
            b = b * r % N;
            */


            BigInteger r_sqr = r * r % N;

            // обчислення a_Montgomery (a = a * r % N)
            a = MontgomeryMultDomain(a, r_sqr, N, result); // це буде a*(r^2), потім отримуємо a*(r^2)*(r^-1) = a * r mod N

            // обчислення b_Montgomery (b = b * r % N)
            b = MontgomeryMultDomain(b, r_sqr, N, result);

            return result;
        }

        public static BigInteger outMontgomeryDomain(BigInteger a, BigInteger m, BigInteger inv)
        {
            return ((a * inv) % m);
        }

        public static BigInteger evklid_inv(BigInteger p, BigInteger a)
        {
            BigInteger l1 = 0, d1 = p, l2 = 1, d2 = a, q = 0, r = 0, h = 0, d = 0;
            BigInteger[] arr = new BigInteger[2];
            q = d1 / d2;
            r = d1 % d2;
            if (r == 0) d = l2;
            else
            {
                while (r != 0)
                {
                    d = l2;
                    q = d1 / d2;
                    r = d1 % d2;
                    if (r == 0) break;
                    h = l1 - l2 * q;
                    l1 = l2;
                    l2 = h;
                    d1 = d2;
                    d2 = r;
                }

            }
            if (d < 0) d += p;
            return d;
        }


        public static BigInteger eeuclid(BigInteger m, BigInteger b, out BigInteger inverse)
        {        // eeuclid( modulus, num whose inv is to be found, variable to put inverse )
                 // Algorithm used from Stallings book
            BigInteger A1 = 1, A2 = 0, A3 = m,
                B1 = 0, B2 = 1, B3 = b,
                T1, T2, T3, Q;

            while (true)
            {
                if (B3 == 0)
                {
                    inverse = 0;
                    return A3;      // A3 = gcd(m,b)
                }

                if (B3 == 1)
                {
                    inverse = B2; // B2 = b^-1 mod m
                    return B3;      // A3 = gcd(m,b)
                }

                Q = A3 / B3;

                T1 = A1 - Q * B1;
                T2 = A2 - Q * B2;
                T3 = A3 - Q * B3;

                A1 = B1; A2 = B2; A3 = B3;
                B1 = T1; B2 = T2; B3 = T3;

            }
        }  

        public static int length_finder(BigInteger a, int c)
        {
            return Convert.ToString((long)a, 2).Length;
        } 

    }
}