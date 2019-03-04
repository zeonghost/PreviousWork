package lesson6;

public class Matix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		java.util.Scanner input = new java.util.Scanner(System.in);
		while(true) {
		System.out.print("enter the number of rows and columns: ");
		int n = input.nextInt();
		double[][] matrix=new double[n][n];
		System.out.print("enter the numbers: ");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				matrix[i][j]=input.nextDouble();
			}
		}
		
		System.out.print("enter the column you want to sum: ");
		int column = input.nextInt();
		
		double sumC=sumColumn(matrix, column);
		System.out.print("This is the sum of the column you want: "+sumC);
		double sumD=sumMajorDiagonal(matrix);
		System.out.print("\nThis is the sum of the major diagonal: "+sumD);
		System.out.print("\nPress any key to continue, or press Q to quit:");
		char a = input.next().charAt(0);
		if((a=='q')||(a=='Q'))
		{
			System.exit(0);
		}
		}
	}
	public static double sumColumn(double[][] m, int columnIndex)
	{
		double sum=0;
		for(int i=0;i<m.length;i++)
		{
				sum=sum+m[i][columnIndex];
		}
		return sum;
	}
	public static double sumMajorDiagonal(double[][] m)
	{
		double sum=0;
		for(int i=0;i<m.length;i++)
		{
			sum=sum+m[i][i];
		}
		return sum;
	}

}
