using System;
using System.Numerics;
using static System.Math;
using static DigitsPower.HelpMethods;



namespace DigitsPower
{
    public static class MontgomeryMethods
    {
        public static BigInteger MontgomeryMultDomain(BigInteger a, BigInteger b, BigInteger m, BigInteger inv)
        {
            return ((a * b * inv) % m);
        }
        public static BigInteger toMontgomeryDomain(ref BigInteger a, ref BigInteger b, BigInteger m)
        {
            BigInteger inverse, R;

            string binary_a = ConvToBinary(a);
            int n = ConvToBinary(m).Length;
            R = TwoPow(n);
            a = (a * R) % m;
            b = (b * R) % m;

            eeuclid(m, R, out inverse);
            return (inverse);
        }
        public static BigInteger outMontgomeryDomain(BigInteger a, BigInteger m, BigInteger inv)
        {
            return ((a * inv) % m);
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