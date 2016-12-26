import java.util.*;

class Vertex implements Comparable<Vertex>{
    public final String name;
    public Edge[] adjacency_list;
    public int dist = MAX_DIST;
    public Vertex prev = NULL;
    public char colour = 'w';
    public Vertex(String s1){
     name = s1; 
}
    public String toString(){
        return name;
    }
    /*public int compare_dist(Vertex v1){
        if(dist <= v1.dist){
            return dist;
        }
        else if(dist > v1.dist){
            return v1.dist;
        }
    }*/
    public int compareTo(Vertex v1){
        return dist.compareTo(v1.dist);
    }
    

}


class Edge{
    public final Vertex dest;
    public Edge(Vertex dt){
        dest = dt;
    }

}

public class graph{
    public static void bfs(Vertex s){
    s.Dist = 0;
    s.colour = "g";
    s.prev = NULL;
    PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
    q.add(s);
    while(!q.isEmpty()){
        Vertex u = q.poll();
        for(Edge e : u.adjacency_list){
            v = e.dest;
            if(v.colour.equals("w")){
                q.remove(v);
                v.colour = "g";
                v.dist = u.dist + 1;
                v.prev = u;
                q.add(v);
            }
            u.colour = "b";
        }
    }
    }



    public static List<Vertex> getShortestDist(Vertex dest)
    {
        List<Vertex> path = new ArrayList<Vertex>();
        for (Vertex ver = dest; ver != null; ver = ver.previous){
            path.add(ver);
        }

        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args){
        Vertex A = new Vertex(getUser_name);
        Vertex B = new Vertex("B");

        A.adjacency_list = new Edge[] {new Edge(C)};
        // Use above syntax to make the edges between people who are connected
        bfs(A);
        List<Vertex> path = getShortestDist(B);
        System.out.println(path + "->");
    }

}