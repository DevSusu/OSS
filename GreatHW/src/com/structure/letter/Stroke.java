package com.structure.letter;

import java.util.ArrayList;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Stroke {
	
	ArrayList<Point> str = new ArrayList<Point>();
	
	public int StrokeAnalyser()
	{
		// ȹ�� �м��ؼ� ��� �Ӽ��� ������ �Ǵ��Ͽ� �������ش�.
		return 0;
	}
	
	public void AddPoint( float x,float y,boolean draw )
	{
		Point tmp = new Point();
		tmp.x = x; tmp.y = y; tmp.draw = draw;
		str.add( tmp );
	}
	
	public void DrawStroke( Canvas canvas , Paint mPaint )
	{
		int i; canvas.drawColor(Color.WHITE);
		
		for( i=1;i<str.size()-1;i++ )
		{
			if( str.get(i).draw ) canvas.drawLine( str.get(i-1).x, str.get(i-1).y, str.get(i).x, str.get(i).y, mPaint );
			else canvas.drawPoint(str.get(i).x, str.get(i).y, mPaint );
		}
	}
	
	public void init()
	{
		str.clear();
	}

}
