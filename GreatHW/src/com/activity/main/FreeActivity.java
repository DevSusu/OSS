package com.activity.main;

import android.app.Activity;
import android.content.Context;
import android.content.res.Resources;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import com.greathw.main.R;
import com.structure.letter.DrawView;

public class FreeActivity extends Activity {
	
	// Touch or TouchMove Event 에 대해  점을 추가해주는 코드만. 선을 그리는 것은 Stroke 객체에서.
	
	ImageView btnErase; ImageView btnExit; DrawView view;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		LinearLayout free = new LinearLayout(this); free.setOrientation(LinearLayout.VERTICAL);
		
		LayoutInflater inflater = (LayoutInflater)getSystemService(
                Context.LAYOUT_INFLATER_SERVICE);
		
		RelativeLayout relative = (RelativeLayout)inflater.inflate(R.layout.free,null);
		
		RelativeLayout.LayoutParams relativeparam = new RelativeLayout.LayoutParams(
				RelativeLayout.LayoutParams.WRAP_CONTENT,
				RelativeLayout.LayoutParams.WRAP_CONTENT);
		
		view = new DrawView(this);
		free.addView( relative,relativeparam ); free.addView(view); setContentView(free);
		
		btnErase = (ImageView)findViewById(R.id.FreeEraseButton);
		btnErase.setOnClickListener(new Button.OnClickListener() {
			public void onClick(View v){
				view.erase();
			}
		});
		btnErase.setOnTouchListener(new OnTouchListener() { //버튼 터치시 이벤트        
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN) // 버튼을 누르고 있을 때
                	btnErase.setBackgroundColor(Color.LTGRAY);
                else if(event.getAction() == MotionEvent.ACTION_UP){ //버튼에서 손을 떼었을 때 
                	btnErase.setBackgroundColor(Color.TRANSPARENT);
                }
                return false;
            }
        }); 
		
		btnExit = (ImageView)findViewById(R.id.FreeExitButton);
		btnExit.setOnClickListener(new Button.OnClickListener(){
			public void onClick(View v){
				finish();
			}
		});
		btnExit.setOnTouchListener(new OnTouchListener() { //버튼 터치시 이벤트        
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN) // 버튼을 누르고 있을 때
                	btnExit.setBackgroundColor(Color.LTGRAY);
                else if(event.getAction() == MotionEvent.ACTION_UP){ //버튼에서 손을 떼었을 때 
                	btnExit.setBackgroundColor(Color.TRANSPARENT);
                }
                return false;
            }
        }); 
	}
}
