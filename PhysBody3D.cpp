#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// =================================================
PhysBody3D::PhysBody3D(btRigidBody* body) : body(body)
{}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	delete body;
}

// ---------------------------------------------------------
void PhysBody3D::Push(float x, float y, float z)
{
	body->applyCentralImpulse(btVector3(x, y, z));
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		body->getWorldTransform().getOpenGLMatrix(matrix);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		btTransform t;
		t.setFromOpenGLMatrix(matrix);
		body->setWorldTransform(t);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btTransform t = body->getWorldTransform();
	t.setOrigin(btVector3(x, y, z));
	body->setWorldTransform(t);
}

void PhysBody3D::SetAsSensor(bool is_sensor)
{
	if (this->is_sensor != is_sensor)
		{
			this->is_sensor = is_sensor;
			if (is_sensor == true)
				body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
			else
				body->setCollisionFlags(body->getCollisionFlags() & ~btCollisionObject::CF_NO_CONTACT_RESPONSE);
		}
}

void  PhysBody3D::AsSensor(bool is_sensor)const {


    if (this->is_sensora != is_sensor)
    {
        this->is_sensora = is_sensor;
        if (is_sensor == true)
            body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        else
            body->setCollisionFlags(body->getCollisionFlags() & ~btCollisionObject::CF_NO_CONTACT_RESPONSE);
    }



}

btRigidBody* PhysBody3D::PointerGet()
{
	return body;
}

btVector3 PhysBody3D::GetLinearVelocity() {
	btVector3 returnV;
	returnV = body->getLinearVelocity();
	return returnV;
}