class Solution {
    public boolean isRobotBounded(String a) {
        char[] s=a.toCharArray();
        int x=0,y=0;
        int dir=2;
        int xx[]={0,0,1,-1};    // RLUD
        int yy[]={1,-1,0,0};
        
        for(char i:s){
            if(i=='G'){
                x+=xx[dir];
                y+=yy[dir];
            }
            else if(i=='L'){
                if(dir==2)  dir=1;
                else if(dir==3) dir=0;
                else if(dir==1) dir=3;
                else        dir=2;
            }
            else{
                if(dir==2)  dir=0;
                else if(dir==3) dir=1;
                else if(dir==1) dir=2;
                else dir=3;
            }
        }
        
        
        return (x==0&&y==0)||dir!=2;
    }
}