package javaFrames;

import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;
import java.io.IOException;

public class resumeFrame extends Frame implements ActionListener,MouseListener{	
	private static final long serialVersionUID = 1L;
	TextField t1,t2,t3,t4,t5,t6,t7,t8,t9;
	TextArea ta1,ta2,ta3,ta4,ta5;
	Label l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,gen;
	List skills;
	Button addskill,b1,b2;
	Choice c,q,year;
	CheckboxGroup gender;
	resumeFrame()
	{
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
		Color color= Color.getHSBColor(170, 41, 56);
		setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
		Label title=new Label("RESUME",Label.CENTER);
		title.setBackground(color);
		title.setBounds(0,30,700,50);
		title.setFont(new Font(Font.MONOSPACED, Font.BOLD, 22));
		
		Panel panel=new Panel();
		panel.setBounds(0,79,150,800);
		panel.setBackground(Color.DARK_GRAY);
		panel.setForeground(color);
		panel.setLayout(null);
		add(panel);
		
		
		Panel panel2=new Panel();
		panel2.setBounds(150,79,2000,800);
		panel2.setBackground(Color.BLACK);
		panel2.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 13));
		panel2.setLayout(null);
		add(panel2);
		
		
		l1=new Label("NAME");
		l1.setBounds(105, 30, 150, 30);
		c=new Choice();
		c.add("Ms.");
		c.add("Mrs.");
		c.add("Mr.");
		c.setBounds(10, 30, 80, 25);
		t1=new TextField("First Name");	
		t1.setBounds(90, 30, 200, 22);
		t1.addMouseListener(this);
		t2=new TextField("Last Name");
		t2.setBounds(300, 30, 200, 22);
		t2.addMouseListener(this);
		
		l2=new Label("CAREER OBJECTIVE");
		l2.setBounds(10, 70, 150, 30);
		ta1=new TextArea("Career Objective");
		ta1.setBounds(10, 65, 490, 45);
		ta1.addMouseListener(this);
		
		l3=new Label("PERSONAL INFO");
		l3.setBounds(34, 130, 150, 30);
		t3=new TextField("D.O.B",2);
		t3.setBounds(10, 130, 140, 25);
		t3.addMouseListener(this);
		gen=new Label("GENDER:");
		gen.setForeground(color);
		gen.setBounds(200, 130, 70, 30);
		gen.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
		gender = new CheckboxGroup();  
        Checkbox male = new Checkbox("Male", gender, false);  
		male.setForeground(color);
        male.setBounds(300,120, 50,50);    
        Checkbox female = new Checkbox("Female", gender, false);   
		female.setForeground(color);
        female.setBounds(400,120, 70,50);    
		ta2=new TextArea("Address");
		ta2.setBounds(10, 165, 490, 45);
		ta2.addMouseListener(this);
		
		l4=new Label("CONTACT ME");
		l4.setBounds(55, 230, 150, 30);
		t4=new TextField("Phone Number");
		t4.setBounds(10, 230, 170, 22);
		t4.addMouseListener(this);
		t5=new TextField("E-mail");
		t5.setBounds(190, 230, 310, 22);
		t5.addMouseListener(this);
		t6=new TextField("LinkedIn Profile Link");
		t6.setBounds(10, 260, 490, 22);
		t6.addMouseListener(this);
		
		l5=new Label("EDUCATION");
		l5.setBounds(65, 300, 150, 30);
		q=new Choice();
		q.add("Qualification");
		q.add("12th");
		q.add("Undergraduate");
		q.add("Postgraduate");
		q.add("Ph.D.");
		q.setBounds(10, 300, 300, 30);
		t7=new TextField("University");
		t7.setBounds(10, 330, 490, 22);
		t7.addMouseListener(this);
		t8=new TextField("Field of study");
		t8.setBounds(10, 360, 320, 22);
		t8.addMouseListener(this);
		year=new Choice();
		year.add("Select Year");
		year.add("1");
		year.add("2");
		year.add("3");
		year.add("4");
		year.add("Graduated");
		year.setBounds(345, 360, 194, 30);
		
		l6=new Label("EXTRA CURRICULAR");
		l6.setBounds(6, 415, 150, 10);
		l7=new Label("ACHIEVEMENTS");
		l7.setBounds(35, 425, 150, 30);
		ta3=new TextArea("Extra Curricular Achievements");
		ta3.setBounds(10, 400, 490, 55);
		ta3.addMouseListener(this);
		
		l8=new Label("SKILLS");
		l8.setBounds(92, 475, 150, 30);
		skills=new List(3);
		skills.setBounds(330, 475, 170, 60);
		t9=new TextField("Add skills one at a time");
		t9.setBounds(10, 475, 300, 22);
		t9.addMouseListener(this);
		addskill=new Button("Add Skill");
		addskill.setBounds(100, 505, 100, 30);
		addskill.addActionListener(this);
		
		l9=new Label("INTERNSHIPS & ");
		l9.setBounds(38, 560, 150, 30);
		l10=new Label("TRAININGS");
		l10.setBounds(66, 590, 150, 20);
		ta4=new TextArea("Mention your past internships and relevant trainings");
		ta4.setBounds(10, 560, 490, 55);
		ta4.addMouseListener(this);
		
		l11=new Label("PROJECTS");
		l11.setBounds(67	, 630, 150, 30);
		ta5=new TextArea("Mention any major projects you made");
		ta5.setBounds(10, 630, 490, 55);
		ta5.addMouseListener(this);
		
		
		panel.add(l1);panel.add(l2);
		panel.add(l3);panel.add(l4);
		panel.add(l5);panel.add(l6);
		panel.add(l7);panel.add(l8);
		panel.add(l9);panel.add(l10);
		panel.add(l11);
		
		
		
		b1=new Button("Submit");
		b1.setBounds(400,690, 100,30);
		b2=new Button("Reset");
		b2.setBounds(290,690, 100,30);
		
		panel2.add(c);
		panel2.add(t1);panel2.add(t2);
		panel2.add(ta1);
		panel2.add(t3);panel2.add(ta2);
		panel2.add(gen);panel2.add(male);panel2.add(female);
		panel2.add(t4);panel2.add(t5);panel2.add(t6);
		panel2.add(q);panel2.add(t7);panel2.add(t8);panel2.add(year);
		panel2.add(ta3);
		panel2.add(t9);panel2.add(addskill);panel2.add(skills);
		panel2.add(ta4);
		panel2.add(ta5);
		panel2.add(b1);panel2.add(b2);
		add(title);
		
		setSize(700,820);
		setLayout(null);
		setVisible(true);
		b1.addActionListener(this);
		b2.addActionListener(this);
		
	}
	
	 public void mouseClicked(MouseEvent e) {
		 
		 	if(e.getSource()==t1)
		 	if(t1.getText().matches("First Name")) 
		 		t1.setText("");
		 	
		 	if(e.getSource()==t2)
		 	if(t2.getText().matches("Last Name")) 
				t2.setText("");
		 	
		 	if(e.getSource()==t3)
			if(t3.getText().matches("D.O.B")) 
				t3.setText("");
			
		 	if(e.getSource()==t4)
			if(t4.getText().matches("Phone Number")) 
				t4.setText("");
			
		 	if(e.getSource()==t5)
			if(t5.getText().matches("E-mail")) 
				t5.setText("");
			
		 	if(e.getSource()==t6)
			if(t6.getText().matches("LinkedIn Profile Link")) 
				t6.setText("");
			
		 	if(e.getSource()==t7)
			if(t7.getText().matches("University")) 
				t7.setText("");
			
		 	if(e.getSource()==t8)
			if(t8.getText().matches("Field of study")) 
				t8.setText("");
		 	
		 	if(e.getSource()==t9)
			if(t9.getText().matches("Add skills one at a time")) 
				t9.setText("");
		 	
		 	if(e.getSource()==ta1)
			if(ta1.getText().matches("Career Objective")) 
				ta1.setText("");
		 	
		 	if(e.getSource()==ta2)
			if(ta2.getText().matches("Address")) 
				ta2.setText("");
		 	
		 	if(e.getSource()==ta3)
			if(ta3.getText().matches("Extra Curricular Achievements")) 
				ta3.setText("");
		 	
		 	if(e.getSource()==ta4)
			if(ta4.getText().matches("Mention your past internships and relevant trainings")) 
				ta4.setText("");
		 	
		 	if(e.getSource()==ta5)
			if(ta5.getText().matches("Mention any major projects you made")) 
				ta5.setText(""); 
	 }
	 public void mouseEntered(MouseEvent e) {}  
	 public void mouseExited(MouseEvent e) {}  
	 public void mousePressed(MouseEvent e) {} 
	 
	 public void mouseReleased(MouseEvent e) {
		 
		 if(t1.getText().matches(""))
			 t1.setText("First Name");
	
			 	if(t2.getText().matches("")) 
					t2.setText("Last Name");
			 	
				if(t3.getText().matches("")) 
					t3.setText("D.O.B");
				
				if(t4.getText().matches("")) 
					t4.setText("Phone Number");
				
				if(t5.getText().matches("")) 
					t5.setText("E-mail");
				
				if(t6.getText().matches("")) 
					t6.setText("LinkedIn Profile Link");
				
				if(t7.getText().matches("")) 
					t7.setText("University");
				
				if(t8.getText().matches("")) 
					t8.setText("Field of study");
			 	
				if(t9.getText().matches("")) 
					t9.setText("Add skills one at a time");
			 	
				if(ta1.getText().matches("")) 
					ta1.setText("Career Objective");
			 	
				if(ta2.getText().matches("")) 
					ta2.setText("Address");
			 	
				if(ta3.getText().matches("")) 
					ta3.setText("Extra Curricular Achievements");
			 	
				if(ta4.getText().matches("")) 
					ta4.setText("Mention your past internships and relevant trainings");
			 	
				if(ta5.getText().matches("")) 
					ta5.setText("Mention any major projects you made");
	 }  
	        
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==addskill) {
			skills.add(t9.getText());
			t9.setText(null);
		}
		if(e.getSource()==b2) {
			
			t1.setText("First Name");
			t2.setText("Last Name");
			t3.setText("D.O.B");
			gender.setSelectedCheckbox(null);
			t4.setText("Phone Number");
			t5.setText("E-mail");
			t6.setText("LinkedIn Profile Link");
			q.select("Qualification");
			t7.setText("University");
			t8.setText("Field of study");
			year.select("Select Year");
			t9.setText("Add skills one at a time");
			skills.removeAll();
			ta1.setText("Career Objective");
			ta2.setText("Address");
			ta3.setText("Extra Curricular Achievements");
			ta4.setText("Mention your past internships and relevant trainings");
			ta5.setText("Mention any major projects you made");
		}


		if(e.getSource()==b1) {
			try {
				FileWriter writer = new FileWriter("resume.txt");
				writer.write("\n___________________________________________________________RESUME_____________________________________________________________________");
				
				if(!t1.getText().matches("First Name")) {
					writer.write("\n\nName : " + c.getSelectedItem() + " " + t1.getText() + " ");
					if(!t2.getText().matches("Last Name"))
							writer.write(t2.getText());
				}
				
				writer.write("\n\n______________________________________________________CAREER OBJECTIVE_________________________________________________________________");
				if(!ta1.getText().matches("Career Objective"))
					writer.write("\n\n" +  ta1.getText());
				
				
				writer.write("\n\n_________________________________________________________PERSONAL INFO_________________________________________________________________");
				if(!t3.getText().matches("D.O.B"))
					writer.write("\n\nDate of Birth : " +  t3.getText());
				if(!(gender.getSelectedCheckbox()==null))
				writer.write("\nGender : " + gender.getSelectedCheckbox().getLabel());
				if(!ta2.getText().matches("Address"))
					writer.write("\nAddress : " +  ta2.getText());
				
				
				writer.write("\n\n______________________________________________________CONTACT INFO_____________________________________________________________________");
				if(!t4.getText().matches("Phone Number"))
					writer.write("\n\nPhone Number : " +  t4.getText());
				if(!t5.getText().matches("E-mail"))
					writer.write("\nE-mail : " +  t5.getText());
				if(!t6.getText().matches("LinkedIn Profile Link"))
					writer.write("\nLinkedIn Profile Link : " +  t6.getText());
				
				writer.write("\n\n___________________________________________________________EDUCATION____________________________________________________________________");
				if(q.getSelectedItem()!="Qualification")
					writer.write("\n\nQualification : " +  q.getSelectedItem());
				if(!t7.getText().matches("University"))
					writer.write("\nUniversity : " +  t7.getText());
				if(!t8.getText().matches("Field of study"))
					writer.write("\nField of study : " +  t8.getText());
				if(year.getSelectedItem()!="Select Year")
					writer.write("\nYear of Study : " + year.getSelectedItem());
				
				writer.write("\n\n__________________________________________________EXTRA CURRICULAR ACHIEVEMENTS_________________________________________________________");
				if(!ta3.getText().matches("Extra Curricular Achievements"))
					writer.write("\n\n"+ ta3.getText());
				
				
				writer.write("\n\n___________________________________________________________SKILLS_______________________________________________________________________\n\n");
				if(!(skills.getItems()==null)) {
					String[] items=skills.getItems();
					for(int i=0;i<items.length;i++)
						writer.write("\n" + (i+1)+ ". " + items[i]);
					
				}
					
				
				writer.write("\n\n______________________________________________INTERNSHIPS AND RELEVANT TRAININGS_________________________________________________________");
				if(!ta4.getText().matches("Mention your past internships and relevant trainings"))
					writer.write("\n\n"+ ta4.getText());
				
				writer.write("\n\n_________________________________________________________MAJOR PROJECTS__________________________________________________________________");
				if(!ta5.getText().matches("Mention any major projects you made"))
					writer.write("\n\n"+ ta5.getText());
				
				writer.close();
			} 
			catch(IOException err) {
				System.out.println("An error occurred.");
			      err.printStackTrace();
			}
			
		}
		
		
		
	}
	public static void main(String[] args) throws IOException {
		resumeFrame f1=new resumeFrame();
	}
}
