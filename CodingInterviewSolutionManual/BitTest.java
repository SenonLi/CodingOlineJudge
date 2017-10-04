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
	 appears exactly once, find the lone integer. */
	public static int findTheLoner(int[] input) {
		int
	}


	public static void main(String[] arg)   {
		String helloWorld = "Hello World!";
		int toTest = 81;
		System.out.println(toTest + (isPowerOfTwo(toTest) ? " is Power of Two. " : " is not Power of Two. ") );
		Integer[] a = new Integer[]{9};
		Integer[] b = new Integer[]{6};
		System.out.println("Before swap: " + a[0] + " and " + b[0]);
		swapInPlace(a, b);
		System.out.println("After swap: " + a[0] + " and " + b[0]);

		printBinaryByte((char)14);
		printBinaryByte(swapBits((char)14));

	}
}