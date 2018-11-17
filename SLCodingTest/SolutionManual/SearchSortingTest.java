/** SearchSortingTest.java */

public class SearchSortingTest {

	/** Question: Searching a sorted array
	 * Given a sorted array of integers and a target value, write a function that finds the index of the target value in the array.
	 * Time: O(n log n)
	 * Space: O(1)      */
	public static int findValueIndex(int[] sortedInput, int targetValue)  {
		return findValueIndex(sortedInput, targetValue, 0, sortedInput.length - 1);
	}

	public static int findValueIndex(int[] sortedInput, int targetValue, int minIndex, int maxIndex)  {
		int midIndex = (minIndex + maxIndex) / 2;
		if (sortedInput[midIndex] == targetValue)     return midIndex;
		if (minIndex >= maxIndex || sortedInput[minIndex] > targetValue || sortedInput[maxIndex] < targetValue) return -1;

		if (sortedInput[midIndex] > targetValue) return findValueIndex(sortedInput, targetValue, minIndex, midIndex);
		else                               return findValueIndex(sortedInput, targetValue, midIndex + 1, maxIndex);
	}


	public static void main(String[] arg)   {
		int[] sortedArray = new int[]   { 0, 1, 3, 5 , 93, 196, 255};
		System.out.println(findValueIndex(sortedArray, 3));

	}
}