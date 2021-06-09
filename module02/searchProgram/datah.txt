// 교육생 정보 헤더 파일

typedef struct Student
{
	char name[10];		// 성함
	char comp[20];		// 기업
	char s[5];			// 성별
	char tel[20];		// 연락처
	char email[50];		// 이메일
	char birth[10];	    // 생년월일
	char major[50];	    // 전공
} student_info;