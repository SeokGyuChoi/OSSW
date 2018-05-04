using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csCannon : MonoBehaviour {
	public GameObject prefab;
	public float power;

	// Use this for initialization
	void Start () {
	}
		GameObject LoadBullet(){
		GameObject bullet = GameObject.Instantiate (prefab)as GameObject;
		bullet.transform.parent = transform;
		bullet.transform.localPosition = Vector3.zero;
		Destroy (bullet, 3.0f);
		return bullet;

	}
	
	// Update is called once per frame
	void Update ()
	{
		if (Input.GetMouseButtonDown (0)) {
			GameObject bullet = LoadBullet ();
			Ray ray = Camera.main.ScreenPointToRay (Input.mousePosition); //째려보는것.중요.외우면좋음
			Vector3 dir = ray.direction.normalized; // 방향
			bullet.GetComponent<Rigidbody> ().velocity = dir * power; // dir = 방향 * 파워
		}
	}
}
