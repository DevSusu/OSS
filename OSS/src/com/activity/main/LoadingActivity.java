package com.activity.main;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.greathw.main.R;

public class LoadingActivity extends Activity {

	Intent intent;
	boolean exist;
	String path;
	File file;
	AlertDialog userdlg;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.loading);

		mHandler.sendEmptyMessageDelayed(0, 1000);

		
		 BufferedReader br = null; StringBuffer sb = new StringBuffer();
		 
		 exist = false;
		 
		 try { br = new BufferedReader( new
		 InputStreamReader(openFileInput("text.txt")));
		 
		 String str = null;
		 
		 while(( str = br.readLine() ) != null ) { sb.append( str ); }
		 
		 br.close();
		 
		 exist = true;
		 
		 } catch (Exception e) {;}
		 		
		// 내장 메모리에 있는 파일을 읽는 방법 = 5_3 에 있다. 4:05

	}

	Handler mHandler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			// TODO Auto-generated method stub
			super.handleMessage(msg);

			if (exist == false) {
				intent = new Intent(LoadingActivity.this, UserActivity.class);
			}

			else {
				intent = new Intent(LoadingActivity.this, MenuActivity.class);
			}

			startActivity(intent);
			finish();
		}
	};
}