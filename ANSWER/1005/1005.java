/*
 * Submit no.26914412
 *
 * 다음 코드를 참고했습니다:
 *  https://www.acmicpc.net/board/view/56162
 */
import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		int loop = s.nextInt();
		for(int i = 0; i < loop; i++){
			ACM a = new ACM(s);
			System.out.println(a.calc());
		}
	}

	private static class ACM {
		public final List<Building> bis;
		public final int dest;

		public ACM(Scanner s){
			int bii = s.nextInt();
			int nii = s.nextInt();

			List<Building> _bis = new ArrayList<>();
			for(int bi = 0; bi < bii; bi++)
				_bis.add(new Building(this, s.nextInt()));
			bis = _bis;

			for(int ni = 0; ni < nii; ni++){
				int von = s.nextInt() - 1;
				int zu = s.nextInt() - 1;
				bis.get(von).registerDirection(zu);
				bis.get(zu).registerPointing(von);
			}

			dest = s.nextInt() - 1;
		}

		public int calc(){
			if(bis.get(dest).targeted == 0) return bis.get(dest).time;
			else{
				Queue<Building> que = new LinkedList<>();
				Map<Building, Integer> cache = new HashMap<>();
				for(Building b : bis){
					if(b.targeted == 0){
						que.add(b);
						cache.put(b, b.time);
					}
				}
				while(!que.isEmpty()){
					Building tmp = que.poll();
					for(Integer tgtNode : tmp.direction){
						PriorityQueue<Integer> pque = new PriorityQueue<>(Comparator.reverseOrder());
						Building tgt = bis.get(tgtNode);
						if(--tgt.targeted == 0){
							for(Integer pitNode : tgt.pointing) pque.add(cache.get(bis.get(pitNode)));
							que.add(tgt);
							cache.put(tgt, pque.poll() + tgt.time);
							if(tgtNode == dest)
								return cache.get(tgt);
						}
					}
				}
			}
			return 0;
		}
	}

	private static class Building {
		private final ACM root;
		public final int time;
		public final List<Integer> direction = new ArrayList<>();
		public final List<Integer> pointing = new ArrayList<>();
		public int targeted = 0;

		public Building(ACM _root, int _time){
			root = _root;
			time = _time;
		}

		public void registerPointing(int von){
			targeted++;
			pointing.add(von);
		}
		public void registerDirection(int zu){
			direction.add(zu);
		}
	}
}
