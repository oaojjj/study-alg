package week6_7;

public class Person {

	private String mName;
	private String mCompany;
	private String mAddress;
	private String mZipcode;
	private String mPones;
	private String mEmail;

	public Person(String name, String company, String address, String zipcode, String pones, String email) {
		mName = name;
		mCompany = company;
		mAddress = address;
		mZipcode = zipcode;
		mPones = pones;
		mEmail = email;
	}

	public String getName() {
		return mName;
	}

	public void setName(String mName) {
		this.mName = mName;
	}

	public String getCompany() {
		return mCompany;
	}

	public void setCompany(String mCompany) {
		this.mCompany = mCompany;
	}

	public String getAddress() {
		return mAddress;
	}

	public void setAddress(String mAddress) {
		this.mAddress = mAddress;
	}

	public String getZipcode() {
		return mZipcode;
	}

	public void setZipcode(String mZipcode) {
		this.mZipcode = mZipcode;
	}

	public String getPones() {
		return mPones;
	}

	public void setPones(String mPones) {
		this.mPones = mPones;
	}

	public String getEmail() {
		return mEmail;
	}

	public void setEmail(String mEmail) {
		this.mEmail = mEmail;
	}

}
