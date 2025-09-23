import java.util.StringTokenizer;
class Solution {
    public List<String> getToken(String version){
        String [] tokens = version.split("\\.");
        List<String> v1= new ArrayList<String>();

        for(String token:tokens){
            v1.add(token);
        }

        return v1;
    }
    public int compareVersion(String version1, String version2) {
        List<String> v1 = getToken(version1);
        List<String> v2 = getToken(version2);
        int n= v1.size();
        int m= v2.size();

        int i=0;

        while(i<n || i<m){
            int a= i<n ? Integer.parseInt(v1.get(i)):0;
            int b= i<m ? Integer.parseInt(v2.get(i)):0;

            if(a<b) return -1;
            else if(a>b) return 1;

            i++;
        }

        return 0;
    }
}