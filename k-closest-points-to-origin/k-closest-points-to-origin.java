class Solution {
    class sort implements Comparator<Integer[]>{
        public int compare(Integer[] a,Integer[] b){
            return b[0]-a[0];
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Integer[]> q=new PriorityQueue<Integer[]>(new sort());
        int[][] ans=new int[k][2];
        for(int i=0;i<points.length;i++){
            int x=points[i][0];
            int y=points[i][1];
                
            q.add(new Integer[]{x*x+y*y,x,y});
            
            if(q.size()==(k+1)){
                q.poll();
            }
        }
        int ind=0;
        while(ind<k){
            ans[ind][0]=q.peek()[1];
            ans[ind++][1]=q.peek()[2];
            q.poll();
        }
        return ans;
    }
}