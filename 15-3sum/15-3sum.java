class Solution {
    public List<List<Integer>> threeSum(int[] arr) {
        Arrays.sort(arr);
        int K=0;
        int n=arr.length;
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        //	ArrayList<Integer> list1 = new ArrayList<Integer>();
        if (n < 3) {
            return list;
        }
        for (int i = 0; i <= n - 3; i++) {
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            int val1 = arr[i];
            int targ = K - val1;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                
                if (j != i + 1 && arr[j] == arr[j - 1]) {
                    j++;	
                    continue;
                }
                
                if (arr[j] + arr[k] == targ) {
                    ArrayList<Integer> sublist = new ArrayList<Integer>();
                    sublist.add(arr[j]);
                    sublist.add(arr[k]);
                    sublist.add(arr[i]);
                    list.add(sublist);
                    j++;
                    k--;
                } else if ((arr[j] + arr[k]) > targ) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return list;
    }
}