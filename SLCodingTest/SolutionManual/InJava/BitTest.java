/** BitTest.java */

public class BitTest {

	/** Question: Power of 2 check
	 * Given an integer, write a function to check if the number is a power of two using bitwise operators. */
	public static boolean isPowerOfTwo(int x)   {
		return (x & (x - 1)) == 0;
	}

	/** Question: Swap in place
	 * Given two integers, write a function to swap them without using any temporary storage. */
	public static void swapInPlace(Integer[] a, Integer[] b)    {
		/** The value of Object "Integer" is also saved as final, so that we need to save in an array to swap
		 * instead of just manipulating with new integer within a small local scope. */
		a[0] = a[0] ^ b[0];
		b[0] = a[0] ^ b[0];
		a[0] = a[0] ^ b[0];
	}

	/** Question: Bit swap
	 * Write a function that takes a byte and swaps the the first 4 bits with the last 4 bits. */
	public static char swapBits(char x) {
		return (char) (((x & 0x0f) << 4) | ((x & 0xf0) >> 4));
	}
	private static void printBinaryByte(char input) {
		char mask = 0x80;
		while(mask != 0) {
			System.out.print((input & mask) == 0 ? "0" : "1");
			mask = (char)(mask >>> 1);
		}
		System.out.println();
	}

	/** Question: Find the lone integer
	 * Given an array of integers where each number appears exactly twice, except for one integer that
	 * appears exactly once, find the lone integer.
	 * Time: O(n)
	 * Space: O(1) */
	public static int findTheLoner(int[] input) {
		int loneInt = 0;
		for (int i=0; i < input.length; i++)    {
			loneInt = loneInt ^ input[i];
		}
		return loneInt;
	}

	/** Question: Same sign check
	 * Given two integers, write a function that checks to see if the two numbers are the same sign using bitwise operators. */
	public static boolean isSameSign(int x, int y)  {
		return (x ^ y) >= 0;
	}

	public static void main(String[] arg)   {
		int toTest = 81;
		System.out.println(toTest + (isPowerOfTwo(toTest) ? " is Power of Two. " : " is not Power of Two. ") );
		Integer[] a = new Integer[]{9};
		Integer[] b = new Integer[]{6};
		System.out.println("Before swap: " + a[0] + " and " + b[0]);
		swapInPlace(a, b);
		System.out.println("After swap: " + a[0] + " and " + b[0]);

		printBinaryByte((char)14);
		printBinaryByte(swapBits((char)14));

		int[] testIntArray = new int[] { 1,3,2, 4, 3, 1, 2 };
		System.out.println("The Loner in the testIntArray is : " + findTheLoner(testIntArray));
		System.out.println(isSameSign(3, 4) ? "3 and 4 are with the same sign." : "3 and 4 are not with the same sign.");
		System.out.println(isSameSign(313, -34) ? "313 and -34 are with the same sign." : "313 and -34 are not with the same sign.");
	}
}